#ifndef ELFREADER_H
#define ELFREADER_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>

#include "controller.h"

namespace Ui {
class ElfReader;
}

class ElfReader : public QWidget
{
    Q_OBJECT

public:
    explicit ElfReader(QWidget *parent = nullptr,
                       QMainWindow *main = nullptr,
                       Controller *control = nullptr);
    ~ElfReader();

private slots:
    void on_pushButton_SwitchToTaskManager_clicked();
    void on_pushButton_SwitchToELFReader_clicked();

    void on_pushButton_DoELFFile_clicked();

    void on_pushButton_CheckTopLevelHeaders_clicked();

    void on_pushButton_CheckSectionsAddressSpace_clicked();

    void on_pushButton_FileSymbolTable_clicked();

    void on_pushButton_ShowBasicNotes_clicked();

    void on_pushButton_ShowRepeatedBlocking_clicked();

    void on_pushButton_ShowDynamicFileSection_clicked();

private:
    void flash_signal_to_controller(std::string command);
    void switch_program_model(int signal);
    void changeInfoTable();

    Ui::ElfReader *ui;
    QMainWindow *main;
    Controller *controller;
    std::vector<std::string> string_collection;
};

#endif // ELFREADER_H
