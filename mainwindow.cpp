#include "mainwindow.h"
#include "ui_mainwindow.h"

QByteArray line="";
QList<QByteArray> lines;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_Button_clicked();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked()
{

    //ui->Result->display(4);
        //File Handling for data over server

}

void MainWindow::on_lcd00_overflow()
{

}

void MainWindow::on_Button_released()
{
    //ui->Result->display(4);
    QString filename=QFileDialog::getOpenFileName(this,
                                                  tr("OPEN FILE"),
                                                  "/home/vartul/qt project/score",
                                                  "Text Files(*.txt)");
    QFile file(filename);
    ui->test->setText("Debugging window");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    int count=0;
        while (!file.atEnd()) {
            count++;
            line= file.readLine();
            //line.insert(24,line.split(','));
            lines = line.split(',');
            //ui->Result->display(21);
            QMessageBox::warning(this,"Data",lines[31]);
            //bool ok;
            //int x=lines[0].toInt(&ok,16);
            //std::cout<<ok<<"\n";
            //std::cout<<count<<"\n";

        }



        //string data = line.;
        //QString s_data = QString::;
}

void MainWindow::on_Button_pressed()
{

}
