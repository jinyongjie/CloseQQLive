#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtimer.h>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    void initUI();
    void killProcess(int minite);
private slots:
    void on_timer();
private:
    Ui::MainWindow *ui;
    QWidget* m_widget1 = nullptr;
    QTimer* m_timer = nullptr;
    int m_seconds=0;
    int m_maxSeconds =  0;
};

#endif // MAINWINDOW_H
