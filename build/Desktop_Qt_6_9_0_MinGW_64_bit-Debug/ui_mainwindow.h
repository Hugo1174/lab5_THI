/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QLabel *statusLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *xLineEdit;
    QLineEdit *yLineEdit;
    QComboBox *colorComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPixelButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setBaseSize(QSize(0, 0));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);

        verticalLayout_2->addWidget(graphicsView);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout_2->addWidget(statusLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        xLineEdit = new QLineEdit(centralwidget);
        xLineEdit->setObjectName("xLineEdit");

        verticalLayout->addWidget(xLineEdit);

        yLineEdit = new QLineEdit(centralwidget);
        yLineEdit->setObjectName("yLineEdit");

        verticalLayout->addWidget(yLineEdit);

        colorComboBox = new QComboBox(centralwidget);
        colorComboBox->addItem(QString());
        colorComboBox->addItem(QString());
        colorComboBox->addItem(QString());
        colorComboBox->setObjectName("colorComboBox");

        verticalLayout->addWidget(colorComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addPixelButton = new QPushButton(centralwidget);
        addPixelButton->setObjectName("addPixelButton");

        horizontalLayout->addWidget(addPixelButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        colorComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Red", nullptr));
        colorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Green", nullptr));
        colorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        addPixelButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\270\321\201\320\265\320\273\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
