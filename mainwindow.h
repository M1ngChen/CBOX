#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {

struct global_varable
{
    int table_end_index = 0;
};

class MainWindow;
}

extern Ui::global_varable gv;

QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_MainPage_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
