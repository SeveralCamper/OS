#include "elfreader.h"
#include "ui_elfreader.h"

ElfReader::ElfReader(QWidget *parent, QMainWindow *main,
                     Controller *control) :
    QWidget(parent),
    ui(new Ui::ElfReader), controller(control) {
    this->main = main;
    ui->setupUi(this);
}

ElfReader::~ElfReader() { delete ui; }

void ElfReader::switch_program_model(int signal) {
    if (signal == 0) {
        this->hide();
        main->show();
    }
}

void ElfReader::flash_signal_to_controller(std::string command) {
    controller->TakeSignal(command);
    changeInfoTable();
}

void ElfReader::changeInfoTable() {
    controller->ReadInfoFromFile();
    string_collection = controller->getStringCollection();
    for (int i = 0; i < (int) string_collection.size(); i++) {
        ui->textBrowser_Output->append(string_collection[i].c_str());
    }
}

void ElfReader::on_pushButton_SwitchToTaskManager_clicked() {
    switch_program_model(0);
}


void ElfReader::on_pushButton_SwitchToELFReader_clicked() {
    switch_program_model(1);
}


void ElfReader::on_pushButton_DoELFFile_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "file ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_CheckTopLevelHeaders_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -h ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_CheckSectionsAddressSpace_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -S ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_FileSymbolTable_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -s ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_ShowBasicNotes_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -n ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_ShowRepeatedBlocking_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -r ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}


void ElfReader::on_pushButton_ShowDynamicFileSection_clicked() {
    ui->textBrowser_Output->clear();
    std::string command = "readelf -d ";
    command += ui->lineEdit_FilePath->text().toStdString();
    flash_signal_to_controller(command);
}

