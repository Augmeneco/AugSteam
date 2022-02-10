#include "optionsform.h"
#include "ui_optionsform.h"
#include <QStackedWidget>

OptionsForm::OptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsForm)
{
    ui->setupUi(this);
    qDebug() << this->width();
}

void OptionsForm::loadConfig(Config *config){
    QString maFilesPath;
    this->config = config;
    if (config->maFilesPath == ""){
        maFilesPath = "None, please select folder";
    }else{
        maFilesPath = config->maFilesPath;
    }

    ui->maFilesPath->setText(
       maFilesPath
    );
}

OptionsForm::~OptionsForm()
{
    delete ui;
}

void OptionsForm::on_pushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory",
                                      QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.config/AugSteam",
                                      QFileDialog::ShowDirsOnly
                                      | QFileDialog::DontResolveSymlinks);
    if (dir == "") return;
    if (!QDir().exists(dir+"/manifest.json")){
        QMessageBox::warning(this, "No maFiles", "There is no maFiles from \"Steam Desktop Authenticator\"");
        return;
    }else{
        QString maFileName = QJsonDocument::fromJson(readFile(dir+"/manifest.json").toUtf8()).object()["entries"].toArray()[0].toObject()["filename"].toString();
        QString nickname = QJsonDocument::fromJson(readFile(dir+"/"+maFileName).toUtf8()).object()["account_name"].toString();
        config->nickname = nickname;

        ui->maFilesPath->setText(dir);
        config->maFilesPath = dir;
        config->save();

        ((QStackedWidget*)parent())->setCurrentIndex(0);
    }
}


void OptionsForm::on_backButton_clicked()
{
    ((QStackedWidget*)parent())->setCurrentIndex(0);
}

