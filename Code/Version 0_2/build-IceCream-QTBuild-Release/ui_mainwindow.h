/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_LoadImage;
    QLabel *label_Filename;
    QGraphicsView *graphicsView_OLEDImage;
    QLabel *label_Status;
    QTextBrowser *textBrowser_CHeaderOutput;
    QPushButton *pushButton_SaveAsCCode;
    QLabel *label_JoyStick;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_gyrY;
    QLabel *label_gyrX;
    QLabel *label_gyrZ;
    QLabel *label_accY;
    QLabel *label_accX;
    QLabel *label_accZ;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_magZ;
    QFrame *line_9;
    QFrame *line_10;
    QLabel *label_magY;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QFrame *line_12;
    QFrame *line_13;
    QLabel *label_magX;
    QLabel *label_16;
    QSpinBox *Brightness;
    QLabel *label_17;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setBaseSize(QSize(750, 650));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setWindowOpacity(0.75);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_LoadImage = new QPushButton(centralWidget);
        pushButton_LoadImage->setObjectName(QString::fromUtf8("pushButton_LoadImage"));
        pushButton_LoadImage->setEnabled(true);
        pushButton_LoadImage->setGeometry(QRect(30, 510, 121, 41));
        label_Filename = new QLabel(centralWidget);
        label_Filename->setObjectName(QString::fromUtf8("label_Filename"));
        label_Filename->setGeometry(QRect(30, 470, 251, 21));
        label_Filename->setScaledContents(false);
        graphicsView_OLEDImage = new QGraphicsView(centralWidget);
        graphicsView_OLEDImage->setObjectName(QString::fromUtf8("graphicsView_OLEDImage"));
        graphicsView_OLEDImage->setGeometry(QRect(30, 200, 256, 256));
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView_OLEDImage->setBackgroundBrush(brush1);
        label_Status = new QLabel(centralWidget);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(40, 120, 661, 31));
        QFont font;
        font.setPointSize(15);
        label_Status->setFont(font);
        label_Status->setAlignment(Qt::AlignCenter);
        textBrowser_CHeaderOutput = new QTextBrowser(centralWidget);
        textBrowser_CHeaderOutput->setObjectName(QString::fromUtf8("textBrowser_CHeaderOutput"));
        textBrowser_CHeaderOutput->setEnabled(true);
        textBrowser_CHeaderOutput->setGeometry(QRect(30, 200, 41, 31));
        QFont font1;
        font1.setPointSize(9);
        textBrowser_CHeaderOutput->setFont(font1);
        textBrowser_CHeaderOutput->setLineWrapMode(QTextEdit::NoWrap);
        pushButton_SaveAsCCode = new QPushButton(centralWidget);
        pushButton_SaveAsCCode->setObjectName(QString::fromUtf8("pushButton_SaveAsCCode"));
        pushButton_SaveAsCCode->setEnabled(false);
        pushButton_SaveAsCCode->setGeometry(QRect(170, 510, 121, 41));
        label_JoyStick = new QLabel(centralWidget);
        label_JoyStick->setObjectName(QString::fromUtf8("label_JoyStick"));
        label_JoyStick->setGeometry(QRect(320, 310, 111, 21));
        label_JoyStick->setScaledContents(false);
        label_JoyStick->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 271, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Verdana"));
        font2.setPointSize(31);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 271, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(19);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        label_2->setFont(font3);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 20, 281, 31));
        label_3->setWordWrap(true);
        label_gyrY = new QLabel(centralWidget);
        label_gyrY->setObjectName(QString::fromUtf8("label_gyrY"));
        label_gyrY->setGeometry(QRect(640, 240, 68, 21));
        label_gyrY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_gyrX = new QLabel(centralWidget);
        label_gyrX->setObjectName(QString::fromUtf8("label_gyrX"));
        label_gyrX->setGeometry(QRect(640, 200, 68, 21));
        label_gyrX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_gyrZ = new QLabel(centralWidget);
        label_gyrZ->setObjectName(QString::fromUtf8("label_gyrZ"));
        label_gyrZ->setGeometry(QRect(640, 280, 68, 21));
        label_gyrZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_accY = new QLabel(centralWidget);
        label_accY->setObjectName(QString::fromUtf8("label_accY"));
        label_accY->setGeometry(QRect(640, 380, 68, 21));
        label_accY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_accX = new QLabel(centralWidget);
        label_accX->setObjectName(QString::fromUtf8("label_accX"));
        label_accX->setGeometry(QRect(640, 340, 68, 21));
        label_accX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_accZ = new QLabel(centralWidget);
        label_accZ->setObjectName(QString::fromUtf8("label_accZ"));
        label_accZ->setGeometry(QRect(640, 420, 68, 21));
        label_accZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(600, 200, 31, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(600, 240, 31, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(600, 280, 31, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(600, 340, 31, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(600, 380, 31, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(600, 420, 31, 21));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(560, 180, 161, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(710, 190, 20, 121));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(560, 300, 161, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(550, 190, 20, 121));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(710, 330, 20, 121));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(560, 320, 161, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(550, 330, 20, 121));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(560, 440, 161, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(460, 210, 91, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(490, 350, 68, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(460, 60, 281, 31));
        label_12->setWordWrap(true);
        label_magZ = new QLabel(centralWidget);
        label_magZ->setObjectName(QString::fromUtf8("label_magZ"));
        label_magZ->setGeometry(QRect(640, 550, 68, 21));
        label_magZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(560, 450, 161, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(550, 460, 20, 121));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_magY = new QLabel(centralWidget);
        label_magY->setObjectName(QString::fromUtf8("label_magY"));
        label_magY->setGeometry(QRect(640, 510, 68, 21));
        label_magY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(600, 470, 31, 21));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(490, 460, 68, 21));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(600, 550, 31, 21));
        line_12 = new QFrame(centralWidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(710, 460, 20, 121));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralWidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(560, 570, 161, 20));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        label_magX = new QLabel(centralWidget);
        label_magX->setObjectName(QString::fromUtf8("label_magX"));
        label_magX->setGeometry(QRect(640, 470, 68, 21));
        label_magX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(600, 510, 31, 21));
        Brightness = new QSpinBox(centralWidget);
        Brightness->setObjectName(QString::fromUtf8("Brightness"));
        Brightness->setGeometry(QRect(350, 520, 81, 31));
        Brightness->setMaximum(254);
        Brightness->setValue(127);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(350, 490, 81, 21));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_LoadImage->raise();
        label_Filename->raise();
        label_Status->raise();
        textBrowser_CHeaderOutput->raise();
        pushButton_SaveAsCCode->raise();
        label_JoyStick->raise();
        graphicsView_OLEDImage->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_gyrY->raise();
        label_gyrX->raise();
        label_gyrZ->raise();
        label_accY->raise();
        label_accX->raise();
        label_accZ->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        line_4->raise();
        line_5->raise();
        line_6->raise();
        line_7->raise();
        line_8->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_magZ->raise();
        line_9->raise();
        line_10->raise();
        label_magY->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        line_12->raise();
        line_13->raise();
        label_magX->raise();
        label_16->raise();
        Brightness->raise();
        label_17->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Visionox | VxD - Ice Cream", 0, QApplication::UnicodeUTF8));
        pushButton_LoadImage->setText(QApplication::translate("MainWindow", "Load Image...", 0, QApplication::UnicodeUTF8));
        label_Filename->setText(QApplication::translate("MainWindow", "No file loaded!", 0, QApplication::UnicodeUTF8));
        label_Status->setText(QApplication::translate("MainWindow", "VxD OLEDHAT - Loading...", 0, QApplication::UnicodeUTF8));
        pushButton_SaveAsCCode->setText(QApplication::translate("MainWindow", "Save C Code", 0, QApplication::UnicodeUTF8));
        label_JoyStick->setText(QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Rocky Road", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#c80000;\">Ice Cream for your Pi.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:14pt;\">Made by engineers for </span><span style=\" font-size:14pt; font-weight:600; text-decoration: underline;\">everyone</span><span style=\" font-size:14pt;\">.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_gyrY->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_gyrX->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_gyrZ->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_accY->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_accX->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_accZ->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Gyro (deg/s)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Acc (G)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:14pt;\">Version: alpha</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_magZ->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_magY->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Mag (uT)", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_magX->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Brightness->setToolTip(QApplication::translate("MainWindow", "0-254", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("MainWindow", "Brightness", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
