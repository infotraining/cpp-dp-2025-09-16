#ifndef QUICKENTRYMEDIATOR_HPP
#define QUICKENTRYMEDIATOR_HPP

#include <QLineEdit>
#include <QListWidget>
#include <QtCore>

class QuickEntryMediator : public QObject
{
    Q_OBJECT
private:
    QLineEdit* lineEdit_;
    QListWidget* listWidget_;

public:
    QuickEntryMediator(QLineEdit* lineEdit, QListWidget* listWidget);
protected slots:
    virtual void on_lineEdit_textChanged(const QString& str);
};

#endif // QUICKENTRYMEDIATOR_HPP
