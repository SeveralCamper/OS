#include "mainwindow.h"
#include <QApplication>
#include "model.h"

int main(int argc, char *argv[]) {
    ModelTaskManager model;
    Controller controller(&model);
    QApplication a(argc, argv);
    MainWindow w(nullptr, &controller);
    w.show();
    return a.exec();
}
