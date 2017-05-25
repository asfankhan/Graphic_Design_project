/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    MyGLWidget *myGLWidget;
    QLabel *lblZ;
    QSlider *horizontalSlider;
    QPushButton *btnRot;
    QPushButton *extrudeButton;
    QLabel *lblX;
    QLabel *lblY;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *Create;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLineEdit *lineEdit_9;
    QLabel *label_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_9;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(897, 596);
        gridLayout = new QGridLayout(Window);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(480, 480));

        horizontalLayout->addWidget(myGLWidget);


        gridLayout->addLayout(horizontalLayout, 0, 4, 1, 1);

        lblZ = new QLabel(Window);
        lblZ->setObjectName(QStringLiteral("lblZ"));

        gridLayout->addWidget(lblZ, 4, 3, 1, 1);

        horizontalSlider = new QSlider(Window);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 3, 1, 1);

        btnRot = new QPushButton(Window);
        btnRot->setObjectName(QStringLiteral("btnRot"));

        gridLayout->addWidget(btnRot, 1, 4, 1, 1);

        extrudeButton = new QPushButton(Window);
        extrudeButton->setObjectName(QStringLiteral("extrudeButton"));
        extrudeButton->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(extrudeButton, 2, 4, 1, 1);

        lblX = new QLabel(Window);
        lblX->setObjectName(QStringLiteral("lblX"));

        gridLayout->addWidget(lblX, 2, 3, 1, 1);

        lblY = new QLabel(Window);
        lblY->setObjectName(QStringLiteral("lblY"));

        gridLayout->addWidget(lblY, 3, 3, 1, 1);

        listWidget = new QListWidget(Window);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 3, 1, 1);

        groupBox = new QGroupBox(Window);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 30, 81, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 61, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 50, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 83, 47, 20));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 70, 81, 20));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(0, 100, 81, 20));
        Create = new QPushButton(groupBox);
        Create->setObjectName(QStringLiteral("Create"));
        Create->setGeometry(QRect(0, 160, 81, 23));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(0, 140, 81, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 120, 47, 13));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 190, 81, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 210, 81, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 250, 81, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 270, 81, 23));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 380, 81, 23));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 450, 81, 23));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(0, 320, 81, 20));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(0, 340, 81, 20));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(0, 360, 81, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 300, 71, 20));
        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(0, 430, 81, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 410, 61, 16));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 510, 81, 23));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 550, 81, 23));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(0, 530, 81, 20));
        lineEdit_10 = new QLineEdit(groupBox);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(0, 470, 81, 20));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 490, 81, 23));

        gridLayout->addWidget(groupBox, 0, 0, 5, 1);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", Q_NULLPTR));
        lblZ->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        btnRot->setText(QApplication::translate("Window", "Auto Rotate", Q_NULLPTR));
        extrudeButton->setText(QApplication::translate("Window", "Extrude", Q_NULLPTR));
        lblX->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        lblY->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Window", "INPUT BOXES", Q_NULLPTR));
        label->setText(QApplication::translate("Window", "#of Rows", Q_NULLPTR));
        label_2->setText(QApplication::translate("Window", "#of Col", Q_NULLPTR));
        label_3->setText(QApplication::translate("Window", "depth", Q_NULLPTR));
        Create->setText(QApplication::translate("Window", "Create", Q_NULLPTR));
        label_4->setText(QApplication::translate("Window", "width", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Window", "Wired", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Window", "Solid", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Window", "Top View", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Window", "Z Side View", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Window", "new color", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Window", "change height", Q_NULLPTR));
        label_5->setText(QApplication::translate("Window", "color x,y,z", Q_NULLPTR));
        label_6->setText(QApplication::translate("Window", "input Height", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Window", "Fractalize", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Window", "Sub Divide", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Window", "cap height", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
