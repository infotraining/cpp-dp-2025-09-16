#include "mydialog.hpp"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    quickEntryMediator = new QuickEntryMediator(ui->txtBrand, ui->lstBrands);
}

MyDialog::~MyDialog()
{
    delete quickEntryMediator;
    delete ui;
}

void MyDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
