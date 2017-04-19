#include "BMX_support.h"
#include "bma2x2.h"
#include "bmg160.h"
#include "bmm050.h"
#include "wiringPi.h"
#include "wiringPiI2C.h"

float gyroBias[3] = {0, 0, 0}, accelBias[3] = {0, 0, 0}, magBias[3] = {0, 0, 0};  // Bias corrections for gyro, accelerometer, mag

static signed char   dig_x1;
static signed char   dig_y1;
static signed char   dig_x2;
static signed char   dig_y2;
static unsigned short dig_z1;
static signed short  dig_z2;
static signed short  dig_z3;
static signed short  dig_z4;
static unsigned char dig_xy1;
static signed char   dig_xy2;
static unsigned short dig_xyz1;

extern int i2cH_BMA, i2cH_BMG, i2cH_BMM;

void fastcompaccelBMX055(float * dest1)
{

    wiringPiI2CWriteReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR, 0x80);  // set all accel offset compensation registers to zero
    wiringPiI2CWriteReg8(i2cH_BMA, BMA2x2_OFFSET_PARAMS_ADDR, 0x20);// set offset targets to 0, 0, and +1 g for x, y, z axes
    wiringPiI2CWriteReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR, 0x20);  // calculate x-axis offset

  char c = wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR);
  while(!(c & 0x10))
    {// check if fast calibration complete
    c = wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR);
    delay(10);
    }

  wiringPiI2CWriteReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR, 0x40);  // calculate y-axis offset

  c = wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR);
    while(!(c & 0x10))
    {// check if fast calibration complete
      c = wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR);
      delay(10);
    }

  wiringPiI2CWriteReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR, 0x60);  // calculate z-axis offset
  while(!(c & 0x10))
  {// check if fast calibration complete
    c = wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_OFFSET_CTRL_ADDR);
    delay(10);
  }


  int compx = wiringPiI2CReadReg8(i2cH_BMA,BMA2x2_OFFSET_X_AXIS_ADDR);
  int compy = wiringPiI2CReadReg8(i2cH_BMA,BMA2x2_OFFSET_Y_AXIS_ADDR);
  int compz = wiringPiI2CReadReg8(i2cH_BMA,BMA2x2_OFFSET_Z_AXIS_ADDR);

  dest1[0] = (float) compx/128.; // accleration bias in g
  dest1[1] = (float) compy/128.; // accleration bias in g
  dest1[2] = (float) compz/128.; // accleration bias in g
}

void readAccelData(short int *destination)
{
  char rawData[6];  // x/y/z accel register data stored here
  int i;
  //readBytes(BMX055_ACC_ADDRESS, BMX055_ACC_D_X_LSB, 6, &rawData[0]);       // Read the six raw data registers into data array
  for(i=0; i < 6; i++)
    rawData[i]=(char)wiringPiI2CReadReg8(i2cH_BMA, BMA2x2_X_AXIS_LSB_ADDR+i);

//  if((rawData[0] & 0x01) && (rawData[2] & 0x01) && (rawData[4] & 0x01)) {  // Check that all 3 axes have new data
  destination[0] = (short int) (((short int)rawData[1] << 8) | (rawData[0] & 0xF0));  // Turn the MSB and LSB into a signed 12-bit value
  destination[1] = (short int) (((short int)rawData[3] << 8) | (rawData[2] & 0xF0));
  destination[2] = (short int) (((short int)rawData[5] << 8) | (rawData[4] & 0xF0));
  //}
}

void readGyroData(short int * destination)
{
    char rawData[6];
    int i;
    for(i=0; i < 6; i++)
        rawData[i]=(char)wiringPiI2CReadReg8(i2cH_BMG, BMG160_RATE_X_LSB_ADDR+i);

    destination[0] = (short int) (((short int)rawData[1] << 8) | (rawData[0] & 0xF0));  // Turn the MSB and LSB into a signed 12-bit value
    destination[1] = (short int) (((short int)rawData[3] << 8) | (rawData[2] & 0xF0));
    destination[2] = (short int) (((short int)rawData[5] << 8) | (rawData[4] & 0xF0));

}

void readMagData(short int *magData)
{
    signed short mdata_x = 0, mdata_y = 0, mdata_z = 0, temp = 0;
    unsigned short data_r = 0;
    char rawData[8];  // x/y/z hall magnetic field data, and Hall resistance data
    int i;

    for(i=0; i < 8; i++)
        rawData[i]=(char)wiringPiI2CReadReg8(i2cH_BMM, BMM050_DATA_X_LSB+i);

    //if(rawData[6] & 0x01) { // Check if data ready status bit is set
        mdata_x = (signed short) (((signed short)rawData[1] << 8) | rawData[0]) >> 3;  // 13-bit signed integer for x-axis field
        mdata_y = (signed short) (((signed short)rawData[3] << 8) | rawData[2]) >> 3;  // 13-bit signed integer for y-axis field
        mdata_z = (signed short) (((signed short)rawData[5] << 8) | rawData[4]) >> 1;  // 15-bit signed integer for z-axis field
        data_r = (unsigned short) (((unsigned short)rawData[7] << 8) | rawData[6]) >> 2;  // 14-bit unsigned integer for Hall resistance

        // calculate temperature compensated 16-bit magnetic fields
        temp = ((signed short)(((unsigned short)((((signed long)dig_xyz1) << 14)/(data_r != 0 ? data_r : dig_xyz1))) - ((unsigned short)0x4000)));
        magData[0] = ((signed short)((((signed long)mdata_x) *\
                   ((((((((signed long)dig_xy2) * ((((signed long)temp) * ((signed long)temp)) >> 7)) +\
                        (((signed long)temp) * ((signed long)(((signed short)dig_xy1) << 7)))) >> 9) +\
                         ((signed long)0x100000)) * ((signed long)(((signed short)dig_x2) + ((signed short)0xA0)))) >> 12)) >> 13)) +\
                        (((signed short)dig_x1) << 3);

       temp = ((signed short)(((unsigned short)((((signed long)dig_xyz1) << 14)/(data_r != 0 ? data_r : dig_xyz1))) - ((unsigned short)0x4000)));
       magData[1] = ((signed short)((((signed long)mdata_y) *\
                    ((((((((signed long)dig_xy2) * ((((signed long)temp) * ((signed long)temp)) >> 7)) +\
                     (((signed long)temp) * ((signed long)(((signed short)dig_xy1) << 7)))) >> 9) +\
                       ((signed long)0x100000)) * ((signed long)(((signed short)dig_y2) + ((signed short)0xA0)))) >> 12)) >> 13)) +\
                (((signed short)dig_y1) << 3);
       magData[2] = (((((signed long)(mdata_z - dig_z4)) << 15) - ((((signed long)dig_z3) * ((signed long)(((signed short)data_r) -\
        ((signed short)dig_xyz1))))>>2))/(dig_z2 + ((signed short)(((((signed long)dig_z1) * ((((signed short)data_r) << 1)))+(1<<15))>>16))));
    //}

}

void trimBMM050()  // get trim values for magnetometer sensitivity
{
  char rawData[2];  //placeholder for 2-byte trim data
  dig_x1 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_X1);
  dig_x2 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_X2);
  dig_y1 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Y1);
  dig_y2 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Y2);
  dig_xy1 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_XY1);
  dig_xy2 = wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_XY2);

  rawData[0]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z1_LSB);
  rawData[1]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z1_MSB);
  dig_z1 = (unsigned short) (((unsigned short)rawData[1] << 8) | rawData[0]);

  rawData[0]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z2_LSB);
  rawData[1]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z2_MSB);
  dig_z2 = (signed short) (((signed short)rawData[1] << 8) | rawData[0]);

  rawData[0]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z3_LSB);
  rawData[1]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z3_MSB);
  dig_z3 = (signed short) (((signed short)rawData[1] << 8) | rawData[0]);

  rawData[0]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z4_LSB);
  rawData[1]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_Z4_MSB);
  dig_z4 = (signed short) (((signed short)rawData[1] << 8) | rawData[0]);

  rawData[0]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_XYZ1_LSB);
  rawData[1]=wiringPiI2CReadReg8(i2cH_BMM, BMM050_DIG_XYZ1_MSB);
  dig_xyz1 = (unsigned short) (((unsigned short)rawData[1] << 8) | rawData[0]);
}
