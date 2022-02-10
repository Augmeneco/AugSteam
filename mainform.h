#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
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

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

    Config *config;

private slots:
    void updateCodeEvent();

    void on_optionsButton_clicked();

private:
    Ui::MainForm *ui;
    QTimer timer;
    QProcess steamProcess;
    QString lastCode = "";
    int statusProgress = 31;
};

#endif // MAINFORM_H
