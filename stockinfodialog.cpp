#include "stockinfodialog.h"
#include "ui_stockinfodialog.h"
#include "QGridLayout"
#include<fstream>
#include"global.h"

StockInfoDialog::StockInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockInfoDialog)
{
    ui->setupUi(this);

    //create a button and connect it with slots
    viewAllBtn = new QPushButton("VIEW ALL", this);
    connect(viewAllBtn, SIGNAL(clicked()), this, SLOT(slotOpenStockFileDiolog()));

    //show txt
    showText = new QTextEdit();

    //viewAll botton layput
    QVBoxLayout *vLayout = new QVBoxLayout();
       vLayout->addStretch();
       vLayout->addWidget(viewAllBtn);
       vLayout->addStretch();
       vLayout->setSpacing(10);

       //layout of the three buttons
           QHBoxLayout *hLayout = new QHBoxLayout(this);
           hLayout->addLayout(vLayout);
           hLayout->addWidget(showText);
           hLayout->setSpacing(10);
           hLayout->setContentsMargins(10, 2, 10, 2);

           //dispaly layout
           setLayout(hLayout);

           //dialog attribution
           resize(800, 600);

           //set background picture
           ui->frame->setStyleSheet("#frame{border-image:url(:/myimages/member_BG.png)}");

           //style sheet
           viewAllBtn->setStyleSheet("font: 15pt" "Arial "";"
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

//distructor
StockInfoDialog::~StockInfoDialog()
{
    delete ui;
}
//end distructor

//function of opening txt and display information in the txt
void StockInfoDialog::slotOpenStockFileDiolog()
{
    showText->clear();
    printTotxt();
    QFile file("stockInformation.txt");

    //successfully open the file
    if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))
        {
            QTextStream textStream(&file);
            while (!textStream.atEnd())
            {
                //print the information of the txt in the dialog
                showText->append(textStream.readLine());
            }
        }

    //fail to open the file
        else
        {

            QMessageBox ::information(NULL, NULL, "open file error");
        }
    file.close();
    //close the file
    }
