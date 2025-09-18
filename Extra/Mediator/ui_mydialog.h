/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label1;
    QLineEdit *txtBrand;
    QLabel *label2;
    QListWidget *lstBrands;

    void setupUi(QWidget *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(324, 298);
        horizontalLayout = new QHBoxLayout(MyDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label1 = new QLabel(MyDialog);
        label1->setObjectName(QStringLiteral("label1"));

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        txtBrand = new QLineEdit(MyDialog);
        txtBrand->setObjectName(QStringLiteral("txtBrand"));

        gridLayout->addWidget(txtBrand, 0, 1, 1, 1);

        label2 = new QLabel(MyDialog);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label2, 1, 0, 1, 1);

        lstBrands = new QListWidget(MyDialog);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        new QListWidgetItem(lstBrands);
        lstBrands->setObjectName(QStringLiteral("lstBrands"));

        gridLayout->addWidget(lstBrands, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QWidget *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "MyDialog", 0));
        label1->setText(QApplication::translate("MyDialog", "Wprowad\305\272 tekst:", 0));
        label2->setText(QApplication::translate("MyDialog", "Producenci:", 0));

        const bool __sortingEnabled = lstBrands->isSortingEnabled();
        lstBrands->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lstBrands->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MyDialog", "Dell", 0));
        QListWidgetItem *___qlistwidgetitem1 = lstBrands->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MyDialog", "Epson", 0));
        QListWidgetItem *___qlistwidgetitem2 = lstBrands->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MyDialog", "EIZO", 0));
        QListWidgetItem *___qlistwidgetitem3 = lstBrands->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MyDialog", "Samsung", 0));
        QListWidgetItem *___qlistwidgetitem4 = lstBrands->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MyDialog", "Brother", 0));
        QListWidgetItem *___qlistwidgetitem5 = lstBrands->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MyDialog", "HP", 0));
        QListWidgetItem *___qlistwidgetitem6 = lstBrands->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MyDialog", "Lenovo", 0));
        QListWidgetItem *___qlistwidgetitem7 = lstBrands->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MyDialog", "Asus", 0));
        QListWidgetItem *___qlistwidgetitem8 = lstBrands->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MyDialog", "Acer", 0));
        QListWidgetItem *___qlistwidgetitem9 = lstBrands->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MyDialog", "Toshiba", 0));
        QListWidgetItem *___qlistwidgetitem10 = lstBrands->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MyDialog", "Sony", 0));
        lstBrands->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
