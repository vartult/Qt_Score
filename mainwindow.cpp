#include "mainwindow.h"
#include "ui_mainwindow.h"

QByteArray line="";
QList<QByteArray> lines;
int hardcord[5][8]={
                    {-45,-30,-18,-6,6,18,30,45},
                    {16,26,22,19,29,35,6,7},
                    {6,7,5,5,29,82,125,64},
                    {16,19,26,31,4,4,6,39},
                    {14,16,23,26,18,21,17,14}
                   };
int max_num=INT_MIN;

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
            for(int i=0;i<lines.size();i++)
            {   bool *ok;
                //std::cout<<lines[0].toHex();
                //QMessageBox::warning(this,"data",lines[i]);
                //QMessageBox::warning(this,"data",QString(c));
                //ui->Result->display();
            }

            ui->lcd00->display(hardcord[1][0]);
            ui->lcd01->display(hardcord[1][1]);
            ui->lcd03->display(hardcord[1][2]);
            ui->lcd04->display(hardcord[1][3]);
            ui->lcd05->display(hardcord[1][4]);
            ui->lcd06->display(hardcord[1][5]);
            ui->lcd07->display(hardcord[1][6]);
            ui->lcd08->display(hardcord[1][7]);
            ui->lcd10->display(hardcord[2][0]);
            ui->lcd11->display(hardcord[2][1]);
            ui->lcd12->display(hardcord[2][2]);
            ui->lcd14->display(hardcord[2][3]);
            ui->lcd15->display(hardcord[2][4]);
            ui->lcd16->display(hardcord[2][5]);
            ui->lcd17->display(hardcord[2][6]);
            ui->lcd18->display(hardcord[2][7]);
            ui->lcd21->display(hardcord[3][0]);
            ui->lcd22->display(hardcord[3][1]);
            ui->lcd23->display(hardcord[3][2]);
            ui->lcd24->display(hardcord[3][3]);
            ui->lcd25->display(hardcord[3][4]);
            ui->lcd26->display(hardcord[3][5]);
            ui->lcd27->display(hardcord[3][6]);
            ui->lcd28->display(hardcord[3][7]);
            ui->lcd31->display(hardcord[4][0]);
            ui->lcd32->display(hardcord[4][1]);
            ui->lcd33->display(hardcord[4][2]);
            ui->lcd34->display(hardcord[4][3]);
            ui->lcd35->display(hardcord[4][4]);
            ui->lcd36->display(hardcord[4][5]);
            ui->lcd37->display(hardcord[4][6]);
            ui->lcd38->display(hardcord[4][7]);


        }


}

void MainWindow::on_Button_pressed()
{

}

void MainWindow::on_res_released()
{
    QMessageBox::warning(this,"INFORMATION","FINDING MAX UPDAING VALUES ON THAT BEHALF");
    //find max
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(hardcord[i][j]>max_num){
                max_num=hardcord[i][j];
            }
        }
    }
    max_num=max_num*0.45;
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(hardcord[i][j]<max_num){
                hardcord[i][j]=0;
            }
        }
    }

    ui->lcd00->display(hardcord[1][0]);
    ui->lcd01->display(hardcord[1][1]);
    ui->lcd03->display(hardcord[1][2]);
    ui->lcd04->display(hardcord[1][3]);
    ui->lcd05->display(hardcord[1][4]);
    ui->lcd06->display(hardcord[1][5]);
    ui->lcd07->display(hardcord[1][6]);
    ui->lcd08->display(hardcord[1][7]);
    ui->lcd10->display(hardcord[2][0]);
    ui->lcd11->display(hardcord[2][1]);
    ui->lcd12->display(hardcord[2][2]);
    ui->lcd14->display(hardcord[2][3]);
    ui->lcd15->display(hardcord[2][4]);
    ui->lcd16->display(hardcord[2][5]);
    ui->lcd17->display(hardcord[2][6]);
    ui->lcd18->display(hardcord[2][7]);
    ui->lcd21->display(hardcord[3][0]);
    ui->lcd22->display(hardcord[3][1]);
    ui->lcd23->display(hardcord[3][2]);
    ui->lcd24->display(hardcord[3][3]);
    ui->lcd25->display(hardcord[3][4]);
    ui->lcd26->display(hardcord[3][5]);
    ui->lcd27->display(hardcord[3][6]);
    ui->lcd28->display(hardcord[3][7]);
    ui->lcd31->display(hardcord[4][0]);
    ui->lcd32->display(hardcord[4][1]);
    ui->lcd33->display(hardcord[4][2]);
    ui->lcd34->display(hardcord[4][3]);
    ui->lcd35->display(hardcord[4][4]);
    ui->lcd36->display(hardcord[4][5]);
    ui->lcd37->display(hardcord[4][6]);
    ui->lcd38->display(hardcord[4][7]);

    int temp_num=0,temp_deno=0;
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(hardcord[i][j]>0){
                temp_num+=hardcord[i][j]*hardcord[0][j];
                temp_deno+=hardcord[0][j];
            }
        }
    }

    int resultant=temp_num/temp_deno;
    ui->Result->display(resultant);

}
