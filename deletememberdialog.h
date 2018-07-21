#ifndef DELETEMEMBERDIALOG_H
#define DELETEMEMBERDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteMemberDialog;
}

class DeleteMemberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteMemberDialog(QWidget *parent = 0);
    ~DeleteMemberDialog();

private slots:
    void on_deleteButton_clicked();

    void on_searchButton_clicked();

    void on_updateButton_clicked();

    void on_exitButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::DeleteMemberDialog *ui;
    std::string oldphonenumber = "";
};

#endif // DELETEMEMBERDIALOG_H
