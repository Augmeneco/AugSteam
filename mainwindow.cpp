#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    config.load();

    mainForm = new MainForm(ui->stackedWidget);
    mainForm->config = &config;
    ui->stackedWidget->insertWidget(0,mainForm);

    optionsForm = new OptionsForm(ui->stackedWidget);
    ui->stackedWidget->insertWidget(1,optionsForm);

    connect(this, &MainWindow::changeConfig,
            optionsForm, &OptionsForm::loadConfig);

    emit changeConfig(&config);

    if (config.maFilesPath == ""){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

