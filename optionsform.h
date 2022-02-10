#ifndef OPTIONSFORM_H
#define OPTIONSFORM_H

#include <QWidget>
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

#include "utils.h"

namespace Ui {
class OptionsForm;
}

class OptionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsForm(QWidget *parent = nullptr);
    ~OptionsForm();

    Config *config;

public slots:
    void loadConfig(Config *config);

private slots:
    void on_pushButton_clicked();

    void on_backButton_clicked();

private:
    Ui::OptionsForm *ui;
    QString defaultConfigPath;
};

#endif // OPTIONSFORM_H
