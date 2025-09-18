#ifndef MYDIALOG_HPP
#define MYDIALOG_HPP

#include "quickentrymediator.hpp"
#include <QWidget>

namespace Ui
{
    class MyDialog;
}

class MyDialog : public QWidget
{
    Q_OBJECT
public:
    MyDialog(QWidget* parent = 0);
    ~MyDialog();

protected:
    void changeEvent(QEvent* e);

private:
    Ui::MyDialog* ui;
    QuickEntryMediator* quickEntryMediator;
};

#endif // MYDIALOG_HPP
