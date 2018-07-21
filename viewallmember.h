#ifndef VIEWALLMEMBER_H
#define VIEWALLMEMBER_H

#include <QDialog>
#include <QFileDialog>
#include <QWidget>
#include<QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QIODevice>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTextStream>
#include <QMessageBox>


namespace Ui {
class viewAllMember;
class QTabWidget;
}

class viewAllMember : public QDialog
{
    Q_OBJECT

public:
    explicit viewAllMember(QWidget *parent = 0);
    ~viewAllMember();

private:
   Ui::viewAllMember *ui;
   QTabWidget *tabWidget;

};

class VipTab:public QWidget
{
    Q_OBJECT

public:
    explicit VipTab(QWidget *parent = 0);
public slots:
    void slotOpenVipFileDiolog();
private:
    QTextEdit *showText;
    QPushButton *viewAllBtn1;
};


class superVipTab:public QWidget
{
    Q_OBJECT

public:
    explicit superVipTab(QWidget *parent = 0);
public slots:
    void slotOpenSuperVipFileDiolog();
private:
    QTextEdit *showText;
    QPushButton *viewAllBtn2;
};

























#endif // VIEWALLMEMBER_H
