#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::MainWindow(QWidget *parent, Controller *controller)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(controller) {
  ui->setupUi(this);

  connect(ui->pushButton_CheckAllProcess, SIGNAL(clicked()), this, SLOT(on_pushButton_CheckAllProcess_clicked()));
  connect(ui->pushButton_CheckAllDirProcess, SIGNAL(clicked()), this, SLOT(on_pushButton_CheckAllDirProcess_clicked()));
  connect(ui->pushButton_ShowProcessTree, SIGNAL(clicked()), this, SLOT(on_pushButton_ShowProcessTree_clicked()));
  connect(ui->pushButton_GenerateProcess, SIGNAL(clicked()), this, SLOT(on_pushButton_GenerateProcess_clicked()));
  connect(ui->pushButton_CheckPID, SIGNAL(clicked()), this, SLOT(on_pushButton_CheckPID_clicked())); // 5, (int) ui->lineEdit_PID->getText()
  connect(ui->pushButton_DeletePID, SIGNAL(clicked()), this, SLOT(on_pushButton_DeletePID_clicked())); // 6, (int) ui->lineEdit_PID->getText()
  connect(ui->pushButton_SwitchToTaskManager, SIGNAL(clicked()), this, SLOT(on_pushButton_SwitchToTaskManager_clicked()));
  connect(ui->pushButton_SwitchToELFReader, SIGNAL(clicked()), this, SLOT(on_pushButton_SwitchToELFReader_clicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::flash_signal_to_controller(int signal, int PID, std::string command) {
    controller->TakeSignal(signal, PID, command);
}

void MainWindow::switch_program_model(int signal) {
    if (signal == 0) {
        ui->pushButton_SwitchToTaskManager->setStyleSheet("background-color: rgb(64,195,208);");
        ui->pushButton_SwitchToELFReader->setStyleSheet("background-color: rgb(215, 215, 215);");
    } else {
        ui->pushButton_SwitchToTaskManager->setStyleSheet("background-color: rgb(215, 215, 215);");
        ui->pushButton_SwitchToELFReader->setStyleSheet("background-color: rgb(64,195,208);");
    }
}

void MainWindow::on_pushButton_CheckAllProcess_clicked() {
    flash_signal_to_controller(1, -1, "ps -e");
}

void MainWindow::on_pushButton_CheckAllDirProcess_clicked() {
    flash_signal_to_controller(2, -1, "ps -T");
}

void MainWindow::on_pushButton_ShowProcessTree_clicked() {
    flash_signal_to_controller(3, -1, "pstree -p");
}

void MainWindow::on_pushButton_GenerateProcess_clicked() {
    flash_signal_to_controller(4, -1, "");
}

void MainWindow::on_pushButton_CheckPID_clicked() {
    std::string command = "ps -p ";
    command += ui->lineEdit_PID->text().toStdString();
    // std::cout << command << std::endl;
    flash_signal_to_controller(5, ui->lineEdit_PID->text().toInt(), command);
}

void MainWindow::on_pushButton_DeletePID_clicked() {
    std::string command = "kill ";
    command += ui->lineEdit_PID->text().toStdString();
    // std::cout << command << std::endl;
    flash_signal_to_controller(6, ui->lineEdit_PID->text().toInt(), command);
}

void MainWindow::on_pushButton_SwitchToTaskManager_clicked() {
    switch_program_model(0);
}

void MainWindow::on_pushButton_SwitchToELFReader_clicked() {
    switch_program_model(1);
}

