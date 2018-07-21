#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"global.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public Q_SLOTS:
    void openCPD();
    void openSID();
     void openGID();
     void openMSID();
     void openNMD();
     void openDMD();
     void openVAMD();
     void openDAD();
     void openMAD();
     void openSAD();

private slots:
     void on_checkOutButton_clicked();
     void on_setDiscountButton_clicked();


     void on_pushButton_clicked();

     void on_setButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
