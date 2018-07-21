#include "mainwindow.h"
#include <QApplication>
#include<QString>
#include<string>
#include<QMessageBox>
#include<fstream>
#include"logindialog.h"
#include"global.h"
using namespace std;

QString password = "000000";
double holidayDiscount = 1.0;
void setPassword();//function prototype

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    setPassword();//Set the password according to the file
    //initializeGoods(); //initialize Goods.txt ONLY ONCE!!!!

    //User login
    LoginDialog ld;
    ld.setWindowTitle("Login");
    if(ld.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else return 0;


    return a.exec();
}

void setPassword()
{
    ifstream in("pw.dat",ios::in|ios::binary);
    if (!in)
    {
        QMessageBox::warning(0, "Warning","File could not opened.", QMessageBox::Yes);
    }

    string pwString;
    in >> pwString;
    password = QString::fromStdString(pwString);
}
