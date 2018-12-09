#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow :
    public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void increase();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int score = 100;
};

#endif // MAINWINDOW_H
