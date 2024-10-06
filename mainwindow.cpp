#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QTabBar>
#include <QFont>
#include "CustomStyle.h"
Ui::global_varable gv = { .table_end_index = 1 };

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置标签栏的字体
    QFont font = ui->MainPage->tabBar()->font();
    font.setPointSize(10); // 设置字体大小
    ui->MainPage->tabBar()->setFont(font);
    // 设置标签栏的方向为水平
    ui->MainPage->tabBar()->setLayoutDirection(Qt::LayoutDirectionAuto);
    ui->MainPage->tabBar()->setStyle(new CustomTabStyle(150,50));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainPage_tabBarClicked(int index)
{
    if(index == gv.table_end_index)
    {
        int index = this->ui->MainPage->count() -1;
        QWidget *newTab = new QWidget();
        QVBoxLayout *newLayout = new QVBoxLayout(newTab);
        newLayout->addWidget(new QLabel(QString("这是标签页 %1").arg(index)));
        this->ui->MainPage->insertTab(index,newTab, QString("标签页 %1").arg(index));
        gv.table_end_index++;
    }
}

