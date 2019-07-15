//*******************************
//*******Vartul Tripathi*********
//*******************************
#include "mainwindow.h"
#include "ui_mainwindow.h"

QByteArray line="";
QString lines="";
//Horizontal Weights
int hor_weight[8]={ -45,-30,-18,-6,6,18,30,45 };
//Vertical Weights
int ver_weight[4]={-5,5,15,25};

//To store the data coming from file
int digits[5][8]={0};
int max_num=INT_MIN;
char x;
QString filename;
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

}

void MainWindow::on_lcd00_overflow()
{

}

void MainWindow::on_Button_released()
{
    //File Handling
    //ui->Result->display(4);
    filename=QFileDialog::getOpenFileName(this,
                                                  tr("OPEN FILE"),
                                                  "/home/vartul/qt project/score",
                                                      "Text Files(*.txt)");
    QString s="Current Channel: ";
    QChar y=filename[filename.size()-1-4];
    s.append(y);
    ui->test->setText(s);
    QFile file(filename);
    //Checking if file opened successfully
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    int count=0;

    QTextStream in(&file);
    QStringList fields;
    //Converting Hexadecimal no to Decimal no by just comparing the value in QByte array
    //Index at 0 and 1 are compared and 16^x is multiplied.
    while(!in.atEnd()) {
        count++;
        QString line = in.readLine();
        fields = line.split(",");
        int hi=1,hj=0;
        int deci=0;
        for(int i=0;i<fields.size();i++)
        {

            if(fields[i][0]=='0')
                deci+=0*16;
            else if(fields[i][0]=='1')
                deci+=1*16;
            else if(fields[i][0]=='2')
                deci+=2*16;
            else if(fields[i][0]=='3')
                deci+=3*16;
            else if(fields[i][0]=='4')
                deci+=4*16;
            else if(fields[i][0]=='5')
                deci+=5*16;
            else if(fields[i][0]=='6')
                deci+=6*16;
            else if(fields[i][0]=='7')
                deci+=7*16;
            else if(fields[i][0]=='8')
                deci+=8*16;
            else if(fields[i][0]=='9')
                deci+=9*16;
            else if(fields[i][0]=='a')
                deci+=10*16;
            else if(fields[i][0]=='b')
                deci+=11*16;
            else if(fields[i][0]=='c')
                deci+=12*16;
            else if(fields[i][0]=='d')
                deci+=13*16;
            else if(fields[i][0]=='e')
                deci+=14*16;
            else
                deci+=15*16;

            if(fields[i][1]=='0')
                deci+=0;
            else if(fields[i][1]=='1')
                deci+=1;
            else if(fields[i][1]=='2')
                deci+=2;
            else if(fields[i][1]=='3')
                deci+=3;
            else if(fields[i][1]=='4')
                deci+=4;
            else if(fields[i][1]=='5')
                deci+=5;
            else if(fields[i][1]=='6')
                deci+=6;
            else if(fields[i][1]=='7')
                deci+=7;
            else if(fields[i][1]=='8')
                deci+=8;
            else if(fields[i][1]=='9')
                deci+=9;
            else if(fields[i][1]=='a')
                deci+=10;
            else if(fields[i][1]=='b')
                deci+=11;
            else if(fields[i][1]=='c')
                deci+=12;
            else if(fields[i][1]=='d')
                deci+=13;
            else if(fields[i][1]=='e')
                deci+=14;
            else
                deci+=15;
            qDebug() << "Amount" << fields[i]<<" "<<deci;

            digits[hi][hj]=deci;
            hj++;
            deci=0;
            if(hj==8)
            {
                hi++;
                hj=0;
            }
            if(hi==6)
                  break;

        }
    }

//Display data on the Channel 1
if(y=='1'||y=='o'){
    ui->lcd00->display(digits[1][0]);
    ui->lcd01->display(digits[1][1]);
    ui->lcd03->display(digits[1][2]);
    ui->lcd04->display(digits[1][3]);
    ui->lcd05->display(digits[1][4]);
    ui->lcd06->display(digits[1][5]);
    ui->lcd07->display(digits[1][6]);
    ui->lcd08->display(digits[1][7]);
    ui->lcd10->display(digits[2][0]);
    ui->lcd11->display(digits[2][1]);
    ui->lcd12->display(digits[2][2]);
    ui->lcd14->display(digits[2][3]);
    ui->lcd15->display(digits[2][4]);
    ui->lcd16->display(digits[2][5]);
    ui->lcd17->display(digits[2][6]);
    ui->lcd18->display(digits[2][7]);
    ui->lcd21->display(digits[3][0]);
    ui->lcd22->display(digits[3][1]);
    ui->lcd23->display(digits[3][2]);
    ui->lcd24->display(digits[3][3]);
    ui->lcd25->display(digits[3][4]);
    ui->lcd26->display(digits[3][5]);
    ui->lcd27->display(digits[3][6]);
    ui->lcd28->display(digits[3][7]);
    ui->lcd31->display(digits[4][0]);
    ui->lcd32->display(digits[4][1]);
    ui->lcd33->display(digits[4][2]);
    ui->lcd34->display(digits[4][3]);
    ui->lcd35->display(digits[4][4]);
    ui->lcd36->display(digits[4][5]);
    ui->lcd37->display(digits[4][6]);
    ui->lcd38->display(digits[4][7]);
}

//Display data on the Channel 2
if(y=='2'){
    ui->lcd00_3->display(digits[1][0]);
    ui->lcd01_3->display(digits[1][1]);
    ui->lcd03_3->display(digits[1][2]);
    ui->lcd04_3->display(digits[1][3]);
    ui->lcd05_3->display(digits[1][4]);
    ui->lcd06_3->display(digits[1][5]);
    ui->lcd07_3->display(digits[1][6]);
    ui->lcd08_3->display(digits[1][7]);
    ui->lcd10_3->display(digits[2][0]);
    ui->lcd11_3->display(digits[2][1]);
    ui->lcd12_3->display(digits[2][2]);
    ui->lcd14_3->display(digits[2][3]);
    ui->lcd15_3->display(digits[2][4]);
    ui->lcd16_3->display(digits[2][5]);
    ui->lcd17_3->display(digits[2][6]);
    ui->lcd18_3->display(digits[2][7]);
    ui->lcd21_2->display(digits[3][0]);
    ui->lcd22_3->display(digits[3][1]);
    ui->lcd23_3->display(digits[3][2]);
    ui->lcd24_3->display(digits[3][3]);
    ui->lcd25_3->display(digits[3][4]);
    ui->lcd26_3->display(digits[3][5]);
    ui->lcd27_3->display(digits[3][6]);
    ui->lcd28_3->display(digits[3][7]);
    ui->lcd31_3->display(digits[4][0]);
    ui->lcd32_3->display(digits[4][1]);
    ui->lcd33_3->display(digits[4][2]);
    ui->lcd34_3->display(digits[4][3]);
    ui->lcd35_3->display(digits[4][4]);
    ui->lcd36_3->display(digits[4][5]);
    ui->lcd37_3->display(digits[4][6]);
    ui->lcd38_3->display(digits[4][7]);
}

//Display data on the Channel 3
if(y=='3'){
    ui->lcd00_4->display(digits[1][0]);
    ui->lcd01_4->display(digits[1][1]);
    ui->lcd03_4->display(digits[1][2]);
    ui->lcd04_4->display(digits[1][3]);
    ui->lcd05_4->display(digits[1][4]);
    ui->lcd06_4->display(digits[1][5]);
    ui->lcd07_4->display(digits[1][6]);
    ui->lcd08_4->display(digits[1][7]);
    ui->lcd10_4->display(digits[2][0]);
    ui->lcd11_4->display(digits[2][1]);
    ui->lcd12_4->display(digits[2][2]);
    ui->lcd14_4->display(digits[2][3]);
    ui->lcd15_4->display(digits[2][4]);
    ui->lcd16_4->display(digits[2][5]);
    ui->lcd17_4->display(digits[2][6]);
    ui->lcd18_4->display(digits[2][7]);
    ui->lcd21_3->display(digits[3][0]);
    ui->lcd22_4->display(digits[3][1]);
    ui->lcd23_4->display(digits[3][2]);
    ui->lcd24_4->display(digits[3][3]);
    ui->lcd25_4->display(digits[3][4]);
    ui->lcd26_4->display(digits[3][5]);
    ui->lcd27_4->display(digits[3][6]);
    ui->lcd28_4->display(digits[3][7]);
    ui->lcd31_4->display(digits[4][0]);
    ui->lcd32_4->display(digits[4][1]);
    ui->lcd33_4->display(digits[4][2]);
    ui->lcd34_4->display(digits[4][3]);
    ui->lcd35_4->display(digits[4][4]);
    ui->lcd36_4->display(digits[4][5]);
    ui->lcd37_4->display(digits[4][6]);
    ui->lcd38_4->display(digits[4][7]);
}
//Display data on the Channel 4

if(y=='4'){
    ui->lcd00_5->display(digits[1][0]);
    ui->lcd01_5->display(digits[1][1]);
    ui->lcd03_5->display(digits[1][2]);
    ui->lcd04_5->display(digits[1][3]);
    ui->lcd05_5->display(digits[1][4]);
    ui->lcd06_5->display(digits[1][5]);
    ui->lcd07_5->display(digits[1][6]);
    ui->lcd08_5->display(digits[1][7]);
    ui->lcd10_5->display(digits[2][0]);
    ui->lcd11_5->display(digits[2][1]);
    ui->lcd12_5->display(digits[2][2]);
    ui->lcd14_5->display(digits[2][3]);
    ui->lcd15_5->display(digits[2][4]);
    ui->lcd16_5->display(digits[2][5]);
    ui->lcd17_5->display(digits[2][6]);
    ui->lcd18_5->display(digits[2][7]);
    ui->lcd21_4->display(digits[3][0]);
    ui->lcd22_5->display(digits[3][1]);
    ui->lcd23_5->display(digits[3][2]);
    ui->lcd24_5->display(digits[3][3]);
    ui->lcd25_5->display(digits[3][4]);
    ui->lcd26_5->display(digits[3][5]);
    ui->lcd27_5->display(digits[3][6]);
    ui->lcd28_5->display(digits[3][7]);
    ui->lcd31_5->display(digits[4][0]);
    ui->lcd32_5->display(digits[4][1]);
    ui->lcd33_5->display(digits[4][2]);
    ui->lcd34_5->display(digits[4][3]);
    ui->lcd35_5->display(digits[4][4]);
    ui->lcd36_5->display(digits[4][5]);
    ui->lcd37_5->display(digits[4][6]);
    ui->lcd38_5->display(digits[4][7]);
}

}

void MainWindow::on_Button_pressed()
{

}

void MainWindow::on_res_released()
{
    //Finding Max out of data for the second filtering process.
    QMessageBox::warning(this,"INFORMATION","PROCESSING");
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(digits[i][j]>max_num){
                max_num=digits[i][j];
            }
        }
    }
    //50mV filtering(1st Filtering)
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(digits[i][j]<2.55){
                digits[i][j]=0;
            }
        }
    }

    //max*.45 value filtering(2nd Filtering)
    double temp = max_num*0.45;
    qDebug() << temp;
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(digits[i][j]<temp){
                digits[i][j]=0;
            }
        }
    }
    //Check for value going to other channels(extreme cases)
    bool left=0,right=0;
    for(int i=1;i<=4;i++)
    {
        if(digits[i][0]>0)
        {
            left=1; break;
        }
        if(digits[i][7]>0)
        {
            right=1; break;
        }
    }


    //Setting Updated Data
    QChar y=filename[filename.size()-1-4];

    //Setting Updated Data on channel 1
    if(y=='1'||y=='o'){
        ui->lcd00->display(digits[1][0]);
        ui->lcd01->display(digits[1][1]);
        ui->lcd03->display(digits[1][2]);
        ui->lcd04->display(digits[1][3]);
        ui->lcd05->display(digits[1][4]);
        ui->lcd06->display(digits[1][5]);
        ui->lcd07->display(digits[1][6]);
        ui->lcd08->display(digits[1][7]);
        ui->lcd10->display(digits[2][0]);
        ui->lcd11->display(digits[2][1]);
        ui->lcd12->display(digits[2][2]);
        ui->lcd14->display(digits[2][3]);
        ui->lcd15->display(digits[2][4]);
        ui->lcd16->display(digits[2][5]);
        ui->lcd17->display(digits[2][6]);
        ui->lcd18->display(digits[2][7]);
        ui->lcd21->display(digits[3][0]);
        ui->lcd22->display(digits[3][1]);
        ui->lcd23->display(digits[3][2]);
        ui->lcd24->display(digits[3][3]);
        ui->lcd25->display(digits[3][4]);
        ui->lcd26->display(digits[3][5]);
        ui->lcd27->display(digits[3][6]);
        ui->lcd28->display(digits[3][7]);
        ui->lcd31->display(digits[4][0]);
        ui->lcd32->display(digits[4][1]);
        ui->lcd33->display(digits[4][2]);
        ui->lcd34->display(digits[4][3]);
        ui->lcd35->display(digits[4][4]);
        ui->lcd36->display(digits[4][5]);
        ui->lcd37->display(digits[4][6]);
        ui->lcd38->display(digits[4][7]);
    }
    //Setting Updated Data on channel 2
    if(y=='2'){
        ui->lcd00_3->display(digits[1][0]);
        ui->lcd01_3->display(digits[1][1]);
        ui->lcd03_3->display(digits[1][2]);
        ui->lcd04_3->display(digits[1][3]);
        ui->lcd05_3->display(digits[1][4]);
        ui->lcd06_3->display(digits[1][5]);
        ui->lcd07_3->display(digits[1][6]);
        ui->lcd08_3->display(digits[1][7]);
        ui->lcd10_3->display(digits[2][0]);
        ui->lcd11_3->display(digits[2][1]);
        ui->lcd12_3->display(digits[2][2]);
        ui->lcd14_3->display(digits[2][3]);
        ui->lcd15_3->display(digits[2][4]);
        ui->lcd16_3->display(digits[2][5]);
        ui->lcd17_3->display(digits[2][6]);
        ui->lcd18_3->display(digits[2][7]);
        ui->lcd21_2->display(digits[3][0]);
        ui->lcd22_3->display(digits[3][1]);
        ui->lcd23_3->display(digits[3][2]);
        ui->lcd24_3->display(digits[3][3]);
        ui->lcd25_3->display(digits[3][4]);
        ui->lcd26_3->display(digits[3][5]);
        ui->lcd27_3->display(digits[3][6]);
        ui->lcd28_3->display(digits[3][7]);
        ui->lcd31_3->display(digits[4][0]);
        ui->lcd32_3->display(digits[4][1]);
        ui->lcd33_3->display(digits[4][2]);
        ui->lcd34_3->display(digits[4][3]);
        ui->lcd35_3->display(digits[4][4]);
        ui->lcd36_3->display(digits[4][5]);
        ui->lcd37_3->display(digits[4][6]);
        ui->lcd38_3->display(digits[4][7]);
    }
    //Setting Updated Data on channel 3
    if(y=='3'){
        ui->lcd00_4->display(digits[1][0]);
        ui->lcd01_4->display(digits[1][1]);
        ui->lcd03_4->display(digits[1][2]);
        ui->lcd04_4->display(digits[1][3]);
        ui->lcd05_4->display(digits[1][4]);
        ui->lcd06_4->display(digits[1][5]);
        ui->lcd07_4->display(digits[1][6]);
        ui->lcd08_4->display(digits[1][7]);
        ui->lcd10_4->display(digits[2][0]);
        ui->lcd11_4->display(digits[2][1]);
        ui->lcd12_4->display(digits[2][2]);
        ui->lcd14_4->display(digits[2][3]);
        ui->lcd15_4->display(digits[2][4]);
        ui->lcd16_4->display(digits[2][5]);
        ui->lcd17_4->display(digits[2][6]);
        ui->lcd18_4->display(digits[2][7]);
        ui->lcd21_3->display(digits[3][0]);
        ui->lcd22_4->display(digits[3][1]);
        ui->lcd23_4->display(digits[3][2]);
        ui->lcd24_4->display(digits[3][3]);
        ui->lcd25_4->display(digits[3][4]);
        ui->lcd26_4->display(digits[3][5]);
        ui->lcd27_4->display(digits[3][6]);
        ui->lcd28_4->display(digits[3][7]);
        ui->lcd31_4->display(digits[4][0]);
        ui->lcd32_4->display(digits[4][1]);
        ui->lcd33_4->display(digits[4][2]);
        ui->lcd34_4->display(digits[4][3]);
        ui->lcd35_4->display(digits[4][4]);
        ui->lcd36_4->display(digits[4][5]);
        ui->lcd37_4->display(digits[4][6]);
        ui->lcd38_4->display(digits[4][7]);
    }
    //Setting Updated Data on channel 4
    if(y=='4'){
        ui->lcd00_5->display(digits[1][0]);
        ui->lcd01_5->display(digits[1][1]);
        ui->lcd03_5->display(digits[1][2]);
        ui->lcd04_5->display(digits[1][3]);
        ui->lcd05_5->display(digits[1][4]);
        ui->lcd06_5->display(digits[1][5]);
        ui->lcd07_5->display(digits[1][6]);
        ui->lcd08_5->display(digits[1][7]);
        ui->lcd10_5->display(digits[2][0]);
        ui->lcd11_5->display(digits[2][1]);
        ui->lcd12_5->display(digits[2][2]);
        ui->lcd14_5->display(digits[2][3]);
        ui->lcd15_5->display(digits[2][4]);
        ui->lcd16_5->display(digits[2][5]);
        ui->lcd17_5->display(digits[2][6]);
        ui->lcd18_5->display(digits[2][7]);
        ui->lcd21_4->display(digits[3][0]);
        ui->lcd22_5->display(digits[3][1]);
        ui->lcd23_5->display(digits[3][2]);
        ui->lcd24_5->display(digits[3][3]);
        ui->lcd25_5->display(digits[3][4]);
        ui->lcd26_5->display(digits[3][5]);
        ui->lcd27_5->display(digits[3][6]);
        ui->lcd28_5->display(digits[3][7]);
        ui->lcd31_5->display(digits[4][0]);
        ui->lcd32_5->display(digits[4][1]);
        ui->lcd33_5->display(digits[4][2]);
        ui->lcd34_5->display(digits[4][3]);
        ui->lcd35_5->display(digits[4][4]);
        ui->lcd36_5->display(digits[4][5]);
        ui->lcd37_5->display(digits[4][6]);
        ui->lcd38_5->display(digits[4][7]);
    }

//    *************Calculating Horizontal and verical angle****************
//    *************value=((sigma)(v[i]*w[i]))/(sigma)(v[i])****************
//    *********************************************************************

    int temp_num=0,temp_deno=0;
    int tempo_num=0,tempo_deno=0;
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(digits[i][j]>0){
                temp_num+=digits[i][j]*hor_weight[j];
                tempo_num+=digits[i][j]*ver_weight[i];
                temp_deno+=digits[i][j];
                tempo_deno+=digits[i][j];
            }
        }
    }
    qDebug()<<temp_num<<temp_deno<<endl;
    double resultant=(double)temp_num/(double)temp_deno;
    double resultant_ver=(double)tempo_num/(double)tempo_deno;
    qDebug()<<tempo_num<<tempo_deno<<resultant_ver<<resultant;

    //Coordinates
    ui->horizontal->display(resultant);
    ui->vertical->display(resultant_ver);

    //In case data in corner of array
    //have to check other arrays for active values
    if(left==1||right==1)
    {

        QMessageBox::warning(this, "Warning", "Corner values delected, Need to check other channels also");
    }

}
