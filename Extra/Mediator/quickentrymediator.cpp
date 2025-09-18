#include "quickentrymediator.hpp"

QuickEntryMediator::QuickEntryMediator(QLineEdit* lineEdit, QListWidget* listWidget)
    : lineEdit_(lineEdit), listWidget_(listWidget)
{
    // sygna�y i sloty
    QObject::connect(lineEdit_, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
}

void QuickEntryMediator::on_lineEdit_textChanged(const QString&)
{
    QString prefix = lineEdit_->text();

    if (prefix.length() == 0)
    {
        listWidget_->clearSelection();
        return;
    }

    bool is_found = false;
    for (int i = 0; i < listWidget_->count(); ++i)
    {
        QListWidgetItem* item = listWidget_->item(i);
        QString item_text = item->text();
        if (item_text.startsWith(prefix))
        {
            item->setSelected(true);
            is_found = true;
        }
    }

    if (!is_found)
        listWidget_->clearSelection();
}
