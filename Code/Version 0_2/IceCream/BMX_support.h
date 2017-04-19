#ifndef BMX_SUPPORT_H
#define BMX_SUPPORT_H

extern float gyroBias[3], accelBias[3], magBias[3];  // Bias corrections for gyro, accelerometer, mag

void fastcompaccelBMX055(float * dest1);
void readAccelData(short int *destination);
void readGyroData(short int * destination);
void readMagData(short int *destination);
void trimBMM050();
#endif // BMX_SUPPORT_H
