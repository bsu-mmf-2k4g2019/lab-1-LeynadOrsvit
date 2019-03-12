#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void CalculatingSem();
    void CalculatingRes();
    void on_pushButton_clicked();

    void on_lineEdit_inputRejected();

    void on_lineEdit_2_inputRejected();

    void on_lineEdit_3_inputRejected();

    void on_lineEdit_4_inputRejected();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
