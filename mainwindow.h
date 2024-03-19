#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn20_clicked();

    void on_btn50_clicked();

    void on_btn100_clicked();

    void on_btn200_clicked();

    void on_btn300_clicked();

    void on_btn500_clicked();

    void on_btn1000_clicked();

    void on_btn_volver_a_retirar_clicked();

    void on_btn_aceptar_clicked();

    void on_btn_solicitar_monto_diferente_clicked();

private:
    Ui::MainWindow *ui;
    void procesarRetiro(int monto);
};
#endif // MAINWINDOW_H
