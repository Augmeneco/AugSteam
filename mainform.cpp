#include "mainform.h"
#include "ui_mainform.h"
#include <QStackedWidget>

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    connect(&timer, &QTimer::timeout,
            this, &MainForm::updateCodeEvent);

    timer.start(1000);
}

void MainForm::updateCodeEvent(){
    if (config->maFilesPath == ""){
        ui->steamCodeExistProgress->setVisible(false);
        ui->mainMessageLabel->setText("Error! No maFiles files for Steam Guard");
        return;
    }

    steamProcess.start("steamguard-cli", {{"-m",config->maFilesPath}} );
    steamProcess.waitForFinished();
    QString code = steamProcess.readAllStandardOutput();

    if (code == ""){
        ui->steamCodeExistProgress->setVisible(false);
        ui->mainMessageLabel->setText("Error! Unknown error with steamguard-cli 0_o");

        return;
    }else{
        ui->mainMessageLabel->setText(config->nickname);

        if (!ui->steamCodeExistProgress->isVisible()){
            ui->steamCodeExistProgress->setVisible(true);
        }
    }

    code.replace("\n","");
    ui->steamCodeLabel->setText(code);


    if (code != lastCode){
        statusProgress = 31;
    }
    if (code == lastCode){
        statusProgress -= 1;
        ui->steamCodeExistProgress->setValue(statusProgress);
    }
    lastCode = code;
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_optionsButton_clicked()
{
    ((QStackedWidget*)parent())->setCurrentIndex(1);
}

