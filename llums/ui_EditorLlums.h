/********************************************************************************
** Form generated from reading ui file 'EditorLlums.ui'
**
** Created: Mon Nov 17 18:15:53 2008
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EDITORLLUMS_H
#define UI_EDITORLLUMS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>
#include "boto.h"
#include "llum.h"
#include "sliderText.h"
#include "textField.h"

class Ui_finestraLlums
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox1;
    QWidget *page1;
    QGroupBox *groupBox11;
    QGroupBox *groupBox9;
    QLabel *textLabel1_2;
    QLabel *textLabel1_3;
    QLabel *textLabel1;
    textField *coorX;
    textField *coorY;
    textField *coorZ;
    QGroupBox *groupBox12;
    QComboBox *referencia;
    QGroupBox *groupBox10;
    QGroupBox *groupBox7;
    boto *botoA;
    QGroupBox *groupBox7_4;
    boto *botoE;
    QGroupBox *groupBox7_3;
    boto *botoD;
    QWidget *page2;
    QCheckBox *spot;
    QGroupBox *groupBoxSpot;
    QGroupBox *groupBox5;
    sliderText *spotExp;
    QGroupBox *groupBoxDirSpot;
    QLabel *textLabel2_2;
    QLabel *textLabel2_3;
    QLabel *textLabel2;
    textField *direccioX;
    textField *direccioY;
    textField *direccioZ;
    QGroupBox *groupBoxAngleSpot;
    sliderText *spotAngle;
    QGroupBox *groupBoxAtenuacioSpot;
    QComboBox *spotAtenuacio;
    textField *grau;
    QCheckBox *activa;
    QPushButton *pushButton1;
    QComboBox *idLlum;
    QLabel *textLabel4;

    void setupUi(QDialog *finestraLlums)
    {
    finestraLlums->setObjectName(QString::fromUtf8("finestraLlums"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(5));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(finestraLlums->sizePolicy().hasHeightForWidth());
    finestraLlums->setSizePolicy(sizePolicy);
    finestraLlums->setMinimumSize(QSize(380, 530));
    finestraLlums->setMaximumSize(QSize(380, 530));
    finestraLlums->setSizeGripEnabled(true);
    gridLayout = new QGridLayout(finestraLlums);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    toolBox1 = new QToolBox(finestraLlums);
    toolBox1->setObjectName(QString::fromUtf8("toolBox1"));
    page1 = new QWidget();
    page1->setObjectName(QString::fromUtf8("page1"));
    page1->setGeometry(QRect(0, 0, 362, 389));
    groupBox11 = new QGroupBox(page1);
    groupBox11->setObjectName(QString::fromUtf8("groupBox11"));
    groupBox11->setGeometry(QRect(10, 200, 351, 161));
    groupBox9 = new QGroupBox(groupBox11);
    groupBox9->setObjectName(QString::fromUtf8("groupBox9"));
    groupBox9->setGeometry(QRect(10, 20, 130, 130));
    textLabel1_2 = new QLabel(groupBox9);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setGeometry(QRect(20, 61, 20, 21));
    textLabel1_2->setWordWrap(false);
    textLabel1_3 = new QLabel(groupBox9);
    textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
    textLabel1_3->setGeometry(QRect(21, 91, 20, 21));
    textLabel1_3->setWordWrap(false);
    textLabel1 = new QLabel(groupBox9);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    textLabel1->setGeometry(QRect(20, 31, 20, 21));
    textLabel1->setWordWrap(false);
    coorX = new textField(groupBox9);
    coorX->setObjectName(QString::fromUtf8("coorX"));
    coorX->setGeometry(QRect(40, 30, 70, 21));
    coorY = new textField(groupBox9);
    coorY->setObjectName(QString::fromUtf8("coorY"));
    coorY->setGeometry(QRect(40, 60, 70, 20));
    coorZ = new textField(groupBox9);
    coorZ->setObjectName(QString::fromUtf8("coorZ"));
    coorZ->setGeometry(QRect(40, 90, 70, 21));
    groupBox12 = new QGroupBox(groupBox11);
    groupBox12->setObjectName(QString::fromUtf8("groupBox12"));
    groupBox12->setGeometry(QRect(160, 20, 181, 131));
    referencia = new QComboBox(groupBox12);
    referencia->setObjectName(QString::fromUtf8("referencia"));
    referencia->setGeometry(QRect(20, 50, 141, 41));
    groupBox10 = new QGroupBox(page1);
    groupBox10->setObjectName(QString::fromUtf8("groupBox10"));
    groupBox10->setGeometry(QRect(10, 0, 351, 201));
    groupBox7 = new QGroupBox(groupBox10);
    groupBox7->setObjectName(QString::fromUtf8("groupBox7"));
    groupBox7->setGeometry(QRect(10, 16, 160, 80));
    botoA = new boto(groupBox7);
    botoA->setObjectName(QString::fromUtf8("botoA"));
    botoA->setGeometry(QRect(10, 20, 140, 51));
    groupBox7_4 = new QGroupBox(groupBox10);
    groupBox7_4->setObjectName(QString::fromUtf8("groupBox7_4"));
    groupBox7_4->setGeometry(QRect(90, 106, 160, 80));
    botoE = new boto(groupBox7_4);
    botoE->setObjectName(QString::fromUtf8("botoE"));
    botoE->setGeometry(QRect(10, 20, 140, 51));
    groupBox7_3 = new QGroupBox(groupBox10);
    groupBox7_3->setObjectName(QString::fromUtf8("groupBox7_3"));
    groupBox7_3->setGeometry(QRect(180, 16, 160, 80));
    botoD = new boto(groupBox7_3);
    botoD->setObjectName(QString::fromUtf8("botoD"));
    botoD->setGeometry(QRect(10, 20, 140, 51));
    toolBox1->addItem(page1, QApplication::translate("finestraLlums", "Par\303\240metres B\303\240sics", 0, QApplication::UnicodeUTF8));
    page2 = new QWidget();
    page2->setObjectName(QString::fromUtf8("page2"));
    page2->setGeometry(QRect(0, 0, 96, 26));
    spot = new QCheckBox(page2);
    spot->setObjectName(QString::fromUtf8("spot"));
    spot->setGeometry(QRect(109, 2, 181, 41));
    groupBoxSpot = new QGroupBox(page2);
    groupBoxSpot->setObjectName(QString::fromUtf8("groupBoxSpot"));
    groupBoxSpot->setGeometry(QRect(0, 50, 370, 301));
    groupBox5 = new QGroupBox(groupBoxSpot);
    groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
    groupBox5->setEnabled(true);
    groupBox5->setGeometry(QRect(179, 108, 180, 70));
    spotExp = new sliderText(groupBox5);
    spotExp->setObjectName(QString::fromUtf8("spotExp"));
    spotExp->setGeometry(QRect(5, 18, 640, 480));
    groupBoxDirSpot = new QGroupBox(groupBoxSpot);
    groupBoxDirSpot->setObjectName(QString::fromUtf8("groupBoxDirSpot"));
    groupBoxDirSpot->setEnabled(true);
    groupBoxDirSpot->setGeometry(QRect(20, 40, 150, 140));
    textLabel2_2 = new QLabel(groupBoxDirSpot);
    textLabel2_2->setObjectName(QString::fromUtf8("textLabel2_2"));
    textLabel2_2->setGeometry(QRect(20, 61, 40, 31));
    textLabel2_2->setWordWrap(false);
    textLabel2_3 = new QLabel(groupBoxDirSpot);
    textLabel2_3->setObjectName(QString::fromUtf8("textLabel2_3"));
    textLabel2_3->setGeometry(QRect(20, 98, 40, 31));
    textLabel2_3->setWordWrap(false);
    textLabel2 = new QLabel(groupBoxDirSpot);
    textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
    textLabel2->setGeometry(QRect(20, 26, 40, 31));
    textLabel2->setWordWrap(false);
    direccioX = new textField(groupBoxDirSpot);
    direccioX->setObjectName(QString::fromUtf8("direccioX"));
    direccioX->setGeometry(QRect(40, 30, 640, 480));
    direccioY = new textField(groupBoxDirSpot);
    direccioY->setObjectName(QString::fromUtf8("direccioY"));
    direccioY->setGeometry(QRect(40, 66, 640, 480));
    direccioZ = new textField(groupBoxDirSpot);
    direccioZ->setObjectName(QString::fromUtf8("direccioZ"));
    direccioZ->setGeometry(QRect(40, 101, 640, 480));
    groupBoxAngleSpot = new QGroupBox(groupBoxSpot);
    groupBoxAngleSpot->setObjectName(QString::fromUtf8("groupBoxAngleSpot"));
    groupBoxAngleSpot->setEnabled(true);
    groupBoxAngleSpot->setGeometry(QRect(180, 38, 180, 70));
    spotAngle = new sliderText(groupBoxAngleSpot);
    spotAngle->setObjectName(QString::fromUtf8("spotAngle"));
    spotAngle->setGeometry(QRect(5, 20, 640, 480));
    groupBoxAtenuacioSpot = new QGroupBox(groupBoxSpot);
    groupBoxAtenuacioSpot->setObjectName(QString::fromUtf8("groupBoxAtenuacioSpot"));
    groupBoxAtenuacioSpot->setGeometry(QRect(10, 200, 350, 80));
    spotAtenuacio = new QComboBox(groupBoxAtenuacioSpot);
    spotAtenuacio->setObjectName(QString::fromUtf8("spotAtenuacio"));
    spotAtenuacio->setGeometry(QRect(10, 30, 250, 30));
    QFont font;
    font.setPointSize(11);
    spotAtenuacio->setFont(font);
    grau = new textField(groupBoxAtenuacioSpot);
    grau->setObjectName(QString::fromUtf8("grau"));
    grau->setGeometry(QRect(271, 36, 640, 480));
    toolBox1->addItem(page2, QApplication::translate("finestraLlums", "Llum Spot", 0, QApplication::UnicodeUTF8));

    gridLayout->addWidget(toolBox1, 1, 0, 1, 3);

    activa = new QCheckBox(finestraLlums);
    activa->setObjectName(QString::fromUtf8("activa"));

    gridLayout->addWidget(activa, 0, 2, 1, 1);

    pushButton1 = new QPushButton(finestraLlums);
    pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

    gridLayout->addWidget(pushButton1, 2, 2, 1, 1);

    idLlum = new QComboBox(finestraLlums);
    idLlum->setObjectName(QString::fromUtf8("idLlum"));

    gridLayout->addWidget(idLlum, 0, 1, 1, 1);

    textLabel4 = new QLabel(finestraLlums);
    textLabel4->setObjectName(QString::fromUtf8("textLabel4"));
    textLabel4->setWordWrap(false);

    gridLayout->addWidget(textLabel4, 0, 0, 1, 1);

    QWidget::setTabOrder(activa, idLlum);

    retranslateUi(finestraLlums);

    QSize size(380, 530);
    size = size.expandedTo(finestraLlums->minimumSizeHint());
    finestraLlums->resize(size);

    QObject::connect(botoE, SIGNAL(released()), finestraLlums, SLOT(specularPressed()));
    QObject::connect(referencia, SIGNAL(activated(int)), finestraLlums, SLOT(puntVista(int)));
    QObject::connect(spotExp, SIGNAL(valueChanged(int)), finestraLlums, SLOT(exponentSpot(int)));
    QObject::connect(direccioZ, SIGNAL(valueChanged(float)), finestraLlums, SLOT(direccioZSpot(float)));
    QObject::connect(direccioY, SIGNAL(valueChanged(float)), finestraLlums, SLOT(direccioYSpot(float)));
    QObject::connect(direccioX, SIGNAL(valueChanged(float)), finestraLlums, SLOT(direccioXSpot(float)));
    QObject::connect(botoD, SIGNAL(released()), finestraLlums, SLOT(difusePressed()));
    QObject::connect(coorZ, SIGNAL(valueChanged(float)), finestraLlums, SLOT(coorZChanged(float)));
    QObject::connect(coorY, SIGNAL(valueChanged(float)), finestraLlums, SLOT(coorYChanged(float)));
    QObject::connect(coorX, SIGNAL(valueChanged(float)), finestraLlums, SLOT(coorXChanged(float)));
    QObject::connect(spotAngle, SIGNAL(valueChanged(int)), finestraLlums, SLOT(angleSpot(int)));
    QObject::connect(spotAtenuacio, SIGNAL(activated(int)), finestraLlums, SLOT(canviarAtenuacio(int)));
    QObject::connect(botoA, SIGNAL(released()), finestraLlums, SLOT(ambientPressed()));
    QObject::connect(spot, SIGNAL(toggled(bool)), finestraLlums, SLOT(activarSpot(bool)));
    QObject::connect(activa, SIGNAL(toggled(bool)), finestraLlums, SLOT(activarLlum(bool)));
    QObject::connect(grau, SIGNAL(valueChanged(float)), finestraLlums, SLOT(modificarAtenuacio(float)));
    QObject::connect(idLlum, SIGNAL(activated(int)), finestraLlums, SLOT(canviarLlum(int)));
    QObject::connect(pushButton1, SIGNAL(pressed()), finestraLlums, SLOT(close()));

    toolBox1->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(finestraLlums);
    } // setupUi

    void retranslateUi(QDialog *finestraLlums)
    {
    finestraLlums->setWindowTitle(QApplication::translate("finestraLlums", "Control de Llums", 0, QApplication::UnicodeUTF8));
    groupBox11->setTitle(QApplication::translate("finestraLlums", "Posici\303\263", 0, QApplication::UnicodeUTF8));
    groupBox9->setTitle(QApplication::translate("finestraLlums", "Coordenades", 0, QApplication::UnicodeUTF8));
    textLabel1_2->setText(QApplication::translate("finestraLlums", "Y", 0, QApplication::UnicodeUTF8));
    textLabel1_3->setText(QApplication::translate("finestraLlums", "Z", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("finestraLlums", "X", 0, QApplication::UnicodeUTF8));
    groupBox12->setTitle(QApplication::translate("finestraLlums", "Refer\303\250ncia", 0, QApplication::UnicodeUTF8));
    referencia->clear();
    referencia->addItem(QApplication::translate("finestraLlums", "Observador", 0, QApplication::UnicodeUTF8));
    referencia->addItem(QApplication::translate("finestraLlums", "Escena", 0, QApplication::UnicodeUTF8));
    referencia->addItem(QApplication::translate("finestraLlums", "Vehicle", 0, QApplication::UnicodeUTF8));
    groupBox10->setTitle(QApplication::translate("finestraLlums", "Color", 0, QApplication::UnicodeUTF8));
    groupBox7->setTitle(QApplication::translate("finestraLlums", "Ambient", 0, QApplication::UnicodeUTF8));
    groupBox7_4->setTitle(QApplication::translate("finestraLlums", "Especular", 0, QApplication::UnicodeUTF8));
    groupBox7_3->setTitle(QApplication::translate("finestraLlums", "Dif\303\263s", 0, QApplication::UnicodeUTF8));
    toolBox1->setItemText(toolBox1->indexOf(page1), QApplication::translate("finestraLlums", "Par\303\240metres B\303\240sics", 0, QApplication::UnicodeUTF8));
    spot->setText(QApplication::translate("finestraLlums", "Llum Spot?", 0, QApplication::UnicodeUTF8));
    groupBoxSpot->setTitle(QApplication::translate("finestraLlums", "Par\303\240metres llum spot", 0, QApplication::UnicodeUTF8));
    groupBox5->setTitle(QApplication::translate("finestraLlums", "Exponent", 0, QApplication::UnicodeUTF8));
    groupBoxDirSpot->setTitle(QApplication::translate("finestraLlums", "Direcci\303\263", 0, QApplication::UnicodeUTF8));
    textLabel2_2->setText(QApplication::translate("finestraLlums", "Y:", 0, QApplication::UnicodeUTF8));
    textLabel2_3->setText(QApplication::translate("finestraLlums", "Z:", 0, QApplication::UnicodeUTF8));
    textLabel2->setText(QApplication::translate("finestraLlums", "X:", 0, QApplication::UnicodeUTF8));
    groupBoxAngleSpot->setTitle(QApplication::translate("finestraLlums", "Angle", 0, QApplication::UnicodeUTF8));
    groupBoxAtenuacioSpot->setTitle(QApplication::translate("finestraLlums", "Atenuaci\303\263", 0, QApplication::UnicodeUTF8));
    spotAtenuacio->clear();
    spotAtenuacio->addItem(QApplication::translate("finestraLlums", "GL_CONSTANT_ATTENUATION", 0, QApplication::UnicodeUTF8));
    spotAtenuacio->addItem(QApplication::translate("finestraLlums", "GL_LINEAR_ATTENUATION", 0, QApplication::UnicodeUTF8));
    spotAtenuacio->addItem(QApplication::translate("finestraLlums", "GL_QUADRATIC_ATTENUATION", 0, QApplication::UnicodeUTF8));
    toolBox1->setItemText(toolBox1->indexOf(page2), QApplication::translate("finestraLlums", "Llum Spot", 0, QApplication::UnicodeUTF8));
    activa->setText(QApplication::translate("finestraLlums", "Activa", 0, QApplication::UnicodeUTF8));
    pushButton1->setText(QApplication::translate("finestraLlums", "Accepta", 0, QApplication::UnicodeUTF8));
    textLabel4->setText(QApplication::translate("finestraLlums", "Llum:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(finestraLlums);
    } // retranslateUi

};

namespace Ui {
    class finestraLlums: public Ui_finestraLlums {};
} // namespace Ui

#endif // UI_EDITORLLUMS_H
