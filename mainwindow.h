#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include <QStandardPaths>
#include <QDir>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "utils.h"
#include "mainform.h"
#include "optionsform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Config config;

signals:
    void changeConfig(Config *config);

private:
    Ui::MainWindow *ui;
    MainForm *mainForm;
    OptionsForm *optionsForm;
};
#endif // MAINWINDOW_H
