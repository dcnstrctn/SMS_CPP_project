#ifndef STOCKINFODIALOG_H
#define STOCKINFODIALOG_H

#include <QFileDialog>
#include <QWidget>
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
class StockInfoDialog;
}

class StockInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StockInfoDialog(QWidget *parent = 0);
    ~StockInfoDialog();
public slots:
    void slotOpenStockFileDiolog();
private:
    Ui::StockInfoDialog *ui;
    QTextEdit *showText;
    QPushButton *viewAllBtn;
};

#endif // STOCKINFODIALOG_H

