#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->lineEditPriceWithoutVAT, &QLineEdit::textChanged,
                     this, &MainWindow::recalculate);

    QObject::connect(ui->radioButton15, &QRadioButton::clicked,
                     this, &MainWindow::recalculate);

    QObject::connect(ui->radioButton21, &QRadioButton::clicked,
                     this, &MainWindow::recalculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recalculate()
{
    bool success;
    double price = ui->lineEditPriceWithoutVAT->text().toDouble(&success);
    if (success) {
        if (ui->radioButton15->isChecked()) {
            price *= 1.15;
        } else {
            price *= 1.21;
        }
        ui->lineEditPriceWithVAT->setText(QString("%1 CZK").arg(price));
    } else {
        ui->lineEditPriceWithVAT->setText("N/A");
    }
}

