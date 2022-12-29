#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include "elfreader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent = nullptr, Controller *controller = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Controller *controller;
    ElfReader *elfWindow;

    std::vector<std::string> string_collection;

    void changeInfoTable();
    void switch_program_model(int signal);
    void flash_signal_to_controller(std::string command);

 private slots:
    void on_pushButton_CheckAllProcess_clicked();
    void on_pushButton_CheckAllDirProcess_clicked();
    void on_pushButton_ShowProcessTree_clicked();
    void on_pushButton_CheckPID_clicked();
    void on_pushButton_DeletePID_clicked();
    void on_pushButton_SwitchToTaskManager_clicked();
    void on_pushButton_SwitchToELFReader_clicked();
    void on_pushButton_CheckOwnProcces_clicked();
};
#endif // MAINWINDOW_H
