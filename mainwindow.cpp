#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QIntValidator>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(735, 600);
    ui->frame->hide();
    ui->frame_2->hide();

    // Add images bancolombia to label
    QPixmap imagen(":/images/bancolombialogo.png");
    if (!imagen.isNull()) {
        ui->lbl_bancolombia_logo->setPixmap(imagen);
        ui->lbl_bancolombia_logo->setScaledContents(true); // Opcional: escalar contenido para ajustarse al tamaño del QLabel
    } else {
        // Manejar el caso de que la imagen no se haya cargado correctamente
    }
    QPixmap imagen_2(":/images/10.jpeg");
    if (!imagen_2.isNull()) {
        ui->lbl_image_billete_10->setPixmap(imagen_2);
        ui->lbl_image_billete_10->setScaledContents(true); // Opcional: escalar contenido para ajustarse al tamaño del QLabel
    } else {
        // Manejar el caso de que la imagen no se haya cargado correctamente
    }
    QPixmap imagen_20(":/images/20.jpeg");
    if (!imagen_20.isNull()) {
        ui->lbl_image_billete_20->setPixmap(imagen_20);
        ui->lbl_image_billete_20->setScaledContents(true); // Opcional: escalar contenido para ajustarse al tamaño del QLabel
    } else {
        // Manejar el caso de que la imagen no se haya cargado correctamente
    }
    QPixmap imagen_50(":/images/50.jpeg");
    if (!imagen_50.isNull()) {
        ui->lbl_image_billete_50->setPixmap(imagen_50);
        ui->lbl_image_billete_50->setScaledContents(true); // Opcional: escalar contenido para ajustarse al tamaño del QLabel
    } else {
        // Manejar el caso de que la imagen no se haya cargado correctamente
    }
    QPixmap imagen_100(":/images/100.png");
    if (!imagen_100.isNull()) {
        ui->lbl_image_billete_100->setPixmap(imagen_100);
        ui->lbl_image_billete_100->setScaledContents(true); // Opcional: escalar contenido para ajustarse al tamaño del QLabel
    } else {
        // Manejar el caso de que la imagen no se haya cargado correctamente
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::procesarRetiro(int monto)
{
    std::vector<int> billetes = {10000, 20000, 50000, 100000};
    std::vector<QLineEdit*> lineEdits = {ui->txt_billete_10, ui->txt_billete_20, ui->txt_billete_50, ui->txt_billete_100};

    std::vector<int> cantidad(4, 0);

    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            if (monto >= billetes[j]) {
                monto -= billetes[j];
                cantidad[j]++;
            }
            if (monto == 0) {
                break;
            } else if (i == 3 && monto != 0) {
                i = -1;
            }
        }
    }
    // Actualizar los QLineEdit con la cantidad de billetes
    for (int i = 0; i < 4; ++i) {
        lineEdits[i]->setText(QString::number(cantidad[i]));
    }
    ui->frame->show();
}


void MainWindow::on_btn20_clicked()
{
    procesarRetiro(20000);
    ui->frame->show();
}


void MainWindow::on_btn50_clicked()
{
    procesarRetiro(50000);
    ui->frame->show();
}


void MainWindow::on_btn100_clicked()
{
    procesarRetiro(100000);
    ui->frame->show();
}


void MainWindow::on_btn200_clicked()
{
    procesarRetiro(200000);
    ui->frame->show();
}


void MainWindow::on_btn300_clicked()
{
    procesarRetiro(300000);
    ui->frame->show();
}


void MainWindow::on_btn500_clicked()
{
    procesarRetiro(500000);
    ui->frame->show();
}


void MainWindow::on_btn1000_clicked()
{
    procesarRetiro(1000000);
    ui->frame->show();
}

void MainWindow::on_btn_volver_a_retirar_clicked()
{
    // mostrar el primer frame
    ui->lbl_tittle_frame1->show();
    ui->lbl_tittle2_frame1->show();
    ui->btn20->show();
    ui->btn50->show();
    ui->btn100->show();
    ui->btn200->show();
    ui->btn300->show();
    ui->btn500->show();
    ui->btn1000->show();
    ui->btn_solicitar_monto_diferente->show();


    ui->frame->hide();
    ui->frame_2->hide();
    ui->txt_valor_diferente->setText("");

}

void MainWindow::on_btn_aceptar_clicked()
{

    ui->btn_solicitar_monto_diferente->hide();

    QString valor = ui->txt_valor_diferente->text();

    // Creamos un QIntValidator para validar que solo se ingresen números enteros
    QIntValidator validator(0, 999999999, this); // Ajusta los límites según tus necesidades

    int pos = 0;
    if (validator.validate(valor, pos) == QValidator::Acceptable) {
        int monto_to_int = valor.toInt();
        if (monto_to_int % 10000 == 0 && monto_to_int <= 2700000) {
            procesarRetiro(monto_to_int);
            ui->frame->show();
        }else{
            QMessageBox::warning(this, "Error", "Ingrese un valor correcto.");
            ui->txt_valor_diferente->setText("");
        }

    } else {
        // Si el valor ingresado no es válido, puedes mostrar un mensaje de error o tomar otra acción
        QMessageBox::warning(this, "Error", "Ingrese un valor numérico válido.");
        ui->txt_valor_diferente->setText("");
    }
}


void MainWindow::on_btn_solicitar_monto_diferente_clicked()
{
    // ocultar el primer frame
    ui->lbl_tittle_frame1->hide();
    ui->lbl_tittle2_frame1->hide();
    ui->btn20->hide();
    ui->btn50->hide();
    ui->btn100->hide();
    ui->btn200->hide();
    ui->btn300->hide();
    ui->btn500->hide();
    ui->btn1000->hide();
    ui->btn_solicitar_monto_diferente->hide();
    ui->frame_2->show();
}

