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
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::flash_signal_to_controller(int signal, int PID, std::string command) {
    controller->TakeSignal(command);
    changeInfoTable();
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
    ui->textBrowser_Output->clear();
    flash_signal_to_controller(1, -1, "ps -e");
}

void MainWindow::on_pushButton_CheckAllDirProcess_clicked() {
    ui->textBrowser_Output->clear();
    flash_signal_to_controller(2, -1, "ps -T");
}

void MainWindow::on_pushButton_ShowProcessTree_clicked() {
    ui->textBrowser_Output->clear();
    flash_signal_to_controller(3, -1, "pstree -p");
}

void MainWindow::on_pushButton_GenerateProcess_clicked() {
    ui->textBrowser_Output->clear();
    char c;
    char *pid = nullptr;
    int pid_1 = (int)getpid(), number = 0, iter = 0;
    while (pid_1 % 10 != 0) {
        number = pid_1 % 10;
        pid_1 = pid_1 / 10;
        c = number + '0';
        pid = (char *) realloc(pid, iter + 1);
        pid[iter] = c;
        iter++;
    }
    ui->textBrowser_Output->append(pid);
    free(pid);
    pid = nullptr;
}

void MainWindow::on_pushButton_CheckPID_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "ps -p ";
    command += ui->lineEdit_PID->text().toStdString();
    flash_signal_to_controller(5, ui->lineEdit_PID->text().toInt(), command);
}

void MainWindow::on_pushButton_DeletePID_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "kill ";
    command += ui->lineEdit_PID->text().toStdString();
    flash_signal_to_controller(6, ui->lineEdit_PID->text().toInt(), command);
}

void MainWindow::changeInfoTable() {
    controller->ReadInfoFromFile();
    string_collection = controller->getStringCollection();
    for (int i = 0; i < (int) string_collection.size(); i++) {
        ui->textBrowser_Output->append(string_collection[i].c_str());
    }
}

void MainWindow::on_pushButton_SwitchToTaskManager_clicked() {
    switch_program_model(0);
}

void MainWindow::on_pushButton_SwitchToELFReader_clicked() {
    switch_program_model(1);
}

