#include "viewallmember.h"
#include "ui_viewallmember.h"
#include "QGridLayout"
#include"global.h"
#include<QtWidgets>
#include<QTabWidget>
viewAllMember::viewAllMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewAllMember)
{
    ui->setupUi(this);
    //create two tab widgets
   tabWidget=new QTabWidget;
   tabWidget->addTab(new VipTab,tr("VIP"));
   tabWidget->addTab(new superVipTab, tr("Super VIP"));
 //set background picture
   ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

   //display layouts
   QHBoxLayout *mainLayout = new QHBoxLayout;
       mainLayout->addWidget(tabWidget);
         setLayout(mainLayout);

           //dialog attribute
           resize(800, 600);
           //style sheet
            tabWidget->setStyleSheet("font: 15pt" "Arial "";"
                                  "border-color:rgba(1,25,53,50);"
                                           "border-radius:6px;"
                                           "color:rgba(1,25,53);");


}

VipTab::VipTab(QWidget *parent):QWidget(parent)
{
    //create a button and connect slots
    viewAllBtn1 = new QPushButton("VIEW ALL", this);
    connect(viewAllBtn1, SIGNAL(clicked()), this, SLOT(slotOpenVipFileDiolog()));

    //show txt
    showText = new QTextEdit();

    //viewAll botton layput
    QVBoxLayout *vLayout = new QVBoxLayout();
       vLayout->addStretch();
       vLayout->addWidget(viewAllBtn1);
       vLayout->addStretch();
       vLayout->setSpacing(10);

       //layout if the three widgets
           QHBoxLayout *hLayout = new QHBoxLayout(this);
           hLayout->addLayout(vLayout);
           hLayout->addWidget(showText);
           hLayout->setSpacing(10);
           hLayout->setContentsMargins(10, 2, 10, 2);

           //display the layout
           setLayout(hLayout);

           //style sheet
                      viewAllBtn1->setStyleSheet("font: 15pt" "Arial "";"
                                                   "background-color:rgba(0,52,63,90);"
                                                     "color:rgba(208,233,255);"
                                                     "border-color:rgba(1,25,53,90);"
                                                     "border-radius:6px;");

                      showText->setStyleSheet("font: 15pt" "Arial "";"
                                  "border-color:rgba(1,25,53,50);"
                                            "border-radius:6px;"
                                         "color:rgba(1,25,53);");

showText->setEnabled(false);
}
//end class VipTab

superVipTab::superVipTab(QWidget *parent):QWidget(parent)
{
    //create a button and connect slots
    viewAllBtn2 = new QPushButton("VIEW ALL", this);
    connect(viewAllBtn2, SIGNAL(clicked()), this, SLOT(slotOpenSuperVipFileDiolog()));

    //show txt
    showText = new QTextEdit();

    //viewAll botton layput
    QVBoxLayout *vLayout = new QVBoxLayout();
       vLayout->addStretch();
       vLayout->addWidget(viewAllBtn2);
       vLayout->addStretch();
       vLayout->setSpacing(10);

       //layout if the three widgets
           QHBoxLayout *hLayout = new QHBoxLayout(this);
           hLayout->addLayout(vLayout);
           hLayout->addWidget(showText);
           hLayout->setSpacing(10);
           hLayout->setContentsMargins(10, 2, 10, 2);

           //display the layout
           setLayout(hLayout);

           //style sheet
                      viewAllBtn2->setStyleSheet("font: 15pt" "Arial "";"
                                  "background-color:rgba(0,52,63,90);"
                                                     "color:rgba(208,233,255);"
                                                     "border-color:rgba(1,25,53,90);"
                                                     "border-radius:6px;");

                      showText->setStyleSheet("font: 15pt" "Arial "";"
                                  "border-color:rgba(1,25,53,50);"
                                              "border-radius:6px;"
                                           "color:rgba(1,25,53);");
showText->setEnabled(false);

}
//end class superVipTab

//distructor
viewAllMember::~viewAllMember()
{
    delete ui;
}
//end distructor

//finction of open super VIP Dialog
void superVipTab::slotOpenSuperVipFileDiolog()
{
    showText->clear();
    svipPrint();
    QFile file("supermemberInformation.txt");
    if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))

        {
            QTextStream textStream(&file);
            while (!textStream.atEnd())
            {
                //display the content in the txt
                showText->append(textStream.readLine());
            }
    }
        //fail to open the file
         else
        {

            QMessageBox ::information(NULL, NULL, "open file error");
        }
    file.close();
    }
//end function slotOpenSuperVipFileDiolog

//finction of open VIP Dialog
void VipTab::slotOpenVipFileDiolog()
{
    showText->clear();
    vipPrint();
    QFile file("memberInformation.txt");
    if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))

        {
            QTextStream textStream(&file);
            while (!textStream.atEnd())
            {
                 //display the content in the txt
                showText->append(textStream.readLine());
            }

        }
    //fail to open the file
        else
        {

            QMessageBox ::information(NULL, NULL, "open file error");
        }
    file.close();
    }
//end function slotOpenVipFileDiolog
