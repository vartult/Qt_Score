#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <iostream>
#include <QString>
#include <math.h>
#include <QDebug>

//My helping global varibale
extern QByteArray line;
//extern QList<QByteArray> lines;
extern int hardcord[5][8];
extern int max_num;
extern QString lines;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_clicked();

    void on_lcd00_overflow();

    void on_Button_pressed();

    void on_Button_released();

    void on_res_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
