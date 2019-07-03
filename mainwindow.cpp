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
    //ui->lcd00->autoFillBackground();
    //ui->lcd00->setPalette(Qt::green);
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
    QChar y=filename[filename.size()-1-4];
    ui->test->setText(y);

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    int count=0;
        while (!file.atEnd()) {
            count++;
            line= file.readLine();
            lines = line.split(',');
            for(int i=0;i<lines.size();i++)
            {
                //QMessageBox::warning(this,"data",lines[i]);
                //QMessageBox::warning(this,"data",QString(c));
                //ui->Result->display();
            }
if(y=='1'){
    //ui->lcd00->display(hardcord[1][0]);
    ui->lcd00->display('a');

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

if(y=='2'){
    ui->lcd00_3->display(hardcord[1][0]);
    ui->lcd01_3->display(hardcord[1][1]);
    ui->lcd03_3->display(hardcord[1][2]);
    ui->lcd04_3->display(hardcord[1][3]);
    ui->lcd05_3->display(hardcord[1][4]);
    ui->lcd06_3->display(hardcord[1][5]);
    ui->lcd07_3->display(hardcord[1][6]);
    ui->lcd08_3->display(hardcord[1][7]);
    ui->lcd10_3->display(hardcord[2][0]);
    ui->lcd11_3->display(hardcord[2][1]);
    ui->lcd12_3->display(hardcord[2][2]);
    ui->lcd14_3->display(hardcord[2][3]);
    ui->lcd15_3->display(hardcord[2][4]);
    ui->lcd16_3->display(hardcord[2][5]);
    ui->lcd17_3->display(hardcord[2][6]);
    ui->lcd18_3->display(hardcord[2][7]);
    ui->lcd21_2->display(hardcord[3][0]);
    ui->lcd22_3->display(hardcord[3][1]);
    ui->lcd23_3->display(hardcord[3][2]);
    ui->lcd24_3->display(hardcord[3][3]);
    ui->lcd25_3->display(hardcord[3][4]);
    ui->lcd26_3->display(hardcord[3][5]);
    ui->lcd27_3->display(hardcord[3][6]);
    ui->lcd28_3->display(hardcord[3][7]);
    ui->lcd31_3->display(hardcord[4][0]);
    ui->lcd32_3->display(hardcord[4][1]);
    ui->lcd33_3->display(hardcord[4][2]);
    ui->lcd34_3->display(hardcord[4][3]);
    ui->lcd35_3->display(hardcord[4][4]);
    ui->lcd36_3->display(hardcord[4][5]);
    ui->lcd37_3->display(hardcord[4][6]);
    ui->lcd38_3->display(hardcord[4][7]);
}

if(y=='3'){
    ui->lcd00_4->display(hardcord[1][0]);
    ui->lcd01_4->display(hardcord[1][1]);
    ui->lcd03_4->display(hardcord[1][2]);
    ui->lcd04_4->display(hardcord[1][3]);
    ui->lcd05_4->display(hardcord[1][4]);
    ui->lcd06_4->display(hardcord[1][5]);
    ui->lcd07_4->display(hardcord[1][6]);
    ui->lcd08_4->display(hardcord[1][7]);
    ui->lcd10_4->display(hardcord[2][0]);
    ui->lcd11_4->display(hardcord[2][1]);
    ui->lcd12_4->display(hardcord[2][2]);
    ui->lcd14_4->display(hardcord[2][3]);
    ui->lcd15_4->display(hardcord[2][4]);
    ui->lcd16_4->display(hardcord[2][5]);
    ui->lcd17_4->display(hardcord[2][6]);
    ui->lcd18_4->display(hardcord[2][7]);
    ui->lcd21_3->display(hardcord[3][0]);
    ui->lcd22_4->display(hardcord[3][1]);
    ui->lcd23_4->display(hardcord[3][2]);
    ui->lcd24_4->display(hardcord[3][3]);
    ui->lcd25_4->display(hardcord[3][4]);
    ui->lcd26_4->display(hardcord[3][5]);
    ui->lcd27_4->display(hardcord[3][6]);
    ui->lcd28_4->display(hardcord[3][7]);
    ui->lcd31_4->display(hardcord[4][0]);
    ui->lcd32_4->display(hardcord[4][1]);
    ui->lcd33_4->display(hardcord[4][2]);
    ui->lcd34_4->display(hardcord[4][3]);
    ui->lcd35_4->display(hardcord[4][4]);
    ui->lcd36_4->display(hardcord[4][5]);
    ui->lcd37_4->display(hardcord[4][6]);
    ui->lcd38_4->display(hardcord[4][7]);
}

if(y=='4'){
    ui->lcd00_5->display(hardcord[1][0]);
    ui->lcd01_5->display(hardcord[1][1]);
    ui->lcd03_5->display(hardcord[1][2]);
    ui->lcd04_5->display(hardcord[1][3]);
    ui->lcd05_5->display(hardcord[1][4]);
    ui->lcd06_5->display(hardcord[1][5]);
    ui->lcd07_5->display(hardcord[1][6]);
    ui->lcd08_5->display(hardcord[1][7]);
    ui->lcd10_5->display(hardcord[2][0]);
    ui->lcd11_5->display(hardcord[2][1]);
    ui->lcd12_5->display(hardcord[2][2]);
    ui->lcd14_5->display(hardcord[2][3]);
    ui->lcd15_5->display(hardcord[2][4]);
    ui->lcd16_5->display(hardcord[2][5]);
    ui->lcd17_5->display(hardcord[2][6]);
    ui->lcd18_5->display(hardcord[2][7]);
    ui->lcd21_4->display(hardcord[3][0]);
    ui->lcd22_5->display(hardcord[3][1]);
    ui->lcd23_5->display(hardcord[3][2]);
    ui->lcd24_5->display(hardcord[3][3]);
    ui->lcd25_5->display(hardcord[3][4]);
    ui->lcd26_5->display(hardcord[3][5]);
    ui->lcd27_5->display(hardcord[3][6]);
    ui->lcd28_5->display(hardcord[3][7]);
    ui->lcd31_5->display(hardcord[4][0]);
    ui->lcd32_5->display(hardcord[4][1]);
    ui->lcd33_5->display(hardcord[4][2]);
    ui->lcd34_5->display(hardcord[4][3]);
    ui->lcd35_5->display(hardcord[4][4]);
    ui->lcd36_5->display(hardcord[4][5]);
    ui->lcd37_5->display(hardcord[4][6]);
    ui->lcd38_5->display(hardcord[4][7]);
}



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
                temp_deno+=hardcord[i][j];
            }
        }
    }

    int resultant=temp_num/temp_deno;
    ui->vertical->display(resultant);

}
