#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QSysInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

char* MainWindow::QString2char(QString s)
{
    char *chStr = NULL;
    QByteArray ba = s.toUtf8();
    chStr = (char *)malloc(ba.length() + 1);
    memset(chStr, 0, ba.length());
    memcpy(chStr, ba.data(), ba.length());
    chStr[ba.length()] = '\0';
    return chStr;
}

void MainWindow::on_pushButton_1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_1->setText(fileName);
}

void MainWindow::on_pushButton_OutPut_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_OutPut->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_2->setText(fileName);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_3->setText(fileName);
}


void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_4->setText(fileName);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_5->setText(fileName);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_6->setText(fileName);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_7->setText(fileName);
}


void MainWindow::on_pushButton_8_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_8->setText(fileName);
}


void MainWindow::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_9->setText(fileName);
}


void MainWindow::on_pushButton_10_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), "files (*.pdf)");
    ui->lineEdit_10->setText(fileName);
}


void MainWindow::on_pushButton_Run_clicked()
{
    QProcess p(this);
    QString cmd, sFile, sPage, pStart, pEnd, sOut;
    QStringList arg;
    char *chStr;

//    p.setWorkingDirectory("/home/bhysn");
//    QString cmd = "/bin/echo " + ui->lineEdit_OutPut->text();
//    QString cmd = "ping -c2 www.126.com";

#if defined (Q_OS_LINUX)
    p.setProgram("bash");
#elif defined (Q_OS_WIN32)
    p.setProgram("cmd");
#endif

    cmd = cmd + "pdftk";

    if (ui->lineEdit_1->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " A=\"" + ui->lineEdit_1->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " A=" + ui->lineEdit_1->text();
#endif
        pStart = ui->spinBox_start1->text() == "0" ? "1" : ui->spinBox_start1->text();
        pEnd = ui->spinBox_end1->text() == "0" ? "end" : ui->spinBox_end1->text();
        sPage += " A" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_2->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " B=\"" + ui->lineEdit_2->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " B=" + ui->lineEdit_2->text();
#endif
        pStart = ui->spinBox_start2->text() == "0" ? "1" : ui->spinBox_start2->text();
        pEnd = ui->spinBox_end2->text() == "0" ? "end" : ui->spinBox_end2->text();
        sPage += " B" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_3->text() != NULL)
    {
//        sFile += " C=\"" + ui->lineEdit_3->text() + "\"";
#if defined (Q_OS_LINUX)
        sFile += " C=\"" + ui->lineEdit_3->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " C=" + ui->lineEdit_3->text();
#endif
        pStart = ui->spinBox_start3->text() == "0" ? "1" : ui->spinBox_start3->text();
        pEnd = ui->spinBox_end3->text() == "0" ? "end" : ui->spinBox_end3->text();
        sPage += " C" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_4->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " D=\"" + ui->lineEdit_4->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " D=" + ui->lineEdit_4->text();
#endif
        pStart = ui->spinBox_start4->text() == "0" ? "1" : ui->spinBox_start4->text();
        pEnd = ui->spinBox_end4->text() == "0" ? "end" : ui->spinBox_end4->text();
        sPage += " D" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_5->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " E=\"" + ui->lineEdit_5->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " E=" + ui->lineEdit_5->text();
#endif
        pStart = ui->spinBox_start5->text() == "0" ? "1" : ui->spinBox_start5->text();
        pEnd = ui->spinBox_end5->text() == "0" ? "end" : ui->spinBox_end5->text();
        sPage += " E" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_6->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " F=\"" + ui->lineEdit_6->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " F=" + ui->lineEdit_6->text();
#endif
        pStart = ui->spinBox_start3->text() == "0" ? "1" : ui->spinBox_start6->text();
        pEnd = ui->spinBox_end6->text() == "0" ? "end" : ui->spinBox_end6->text();
        sPage += " F" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_7->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " G=\"" + ui->lineEdit_7->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " G=" + ui->lineEdit_7->text();
#endif
        pStart = ui->spinBox_start7->text() == "0" ? "1" : ui->spinBox_start7->text();
        pEnd = ui->spinBox_end7->text() == "0" ? "end" : ui->spinBox_end7->text();
        sPage += " G" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_8->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " H=\"" + ui->lineEdit_8->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " H=" + ui->lineEdit_8->text();
#endif
        pStart = ui->spinBox_start8->text() == "0" ? "1" : ui->spinBox_start8->text();
        pEnd = ui->spinBox_end8->text() == "0" ? "end" : ui->spinBox_end8->text();
        sPage += " H" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_9->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " I=\"" + ui->lineEdit_9->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " I=" + ui->lineEdit_9->text();
#endif
        pStart = ui->spinBox_start9->text() == "0" ? "1" : ui->spinBox_start9->text();
        pEnd = ui->spinBox_end9->text() == "0" ? "end" : ui->spinBox_end9->text();
        sPage += " I" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_10->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sFile += " J=\"" + ui->lineEdit_10->text() + "\"";
#elif defined(Q_OS_WIN32)
        sFile += " J=" + ui->lineEdit_10->text();
#endif
        pStart = ui->spinBox_start10->text() == "0" ? "1" : ui->spinBox_start10->text();
        pEnd = ui->spinBox_end10->text() == "0" ? "end" : ui->spinBox_end10->text();
        sPage += " J" + pStart + "-" + pEnd;
    }

    if (ui->lineEdit_OutPut->text() != NULL && ui->lineEdit_1->text() != NULL)
    {
#if defined (Q_OS_LINUX)
        sOut = "\"" + ui->lineEdit_OutPut->text() + "\"";
#elif defined(Q_OS_WIN32)
        sOut = ui->lineEdit_OutPut->text();
#endif
        cmd += sFile + " cat" + sPage + " output " + sOut;
    }

    if (ui->lineEdit_1->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" &&  ui->lineEdit_4->text() == "" && \
            ui->lineEdit_5->text() == "" &&  ui->lineEdit_6->text() == "" && ui->lineEdit_7->text() == "" && ui->lineEdit_8->text() == "" && \
            ui->lineEdit_9->text() == "" && ui->lineEdit_10->text() == "")
    {
        QMessageBox::warning(this, "Error", "Please choose file.");
        return;
    }

    std::cout << cmd.toStdString() << std::endl;

    chStr = QString2char(cmd);

#if defined (Q_OS_LINUX)
    arg << "-c" << chStr ;
#elif defined (Q_OS_WIN32)
    arg << "/c" << chStr ;
#endif

    p.setArguments(arg);
    p.start();
    p.waitForStarted();
    p.waitForFinished();
    QString s = QString::fromUtf8(p.readAllStandardError());
    if (s == "")
    {
        char *chStr2 = QString2char(s);
        std::cout << chStr2 << std::endl;
        free(chStr2);
        QMessageBox::information(this, sOut, "成功！");
    }
    else
    {
        QMessageBox::warning(this, "Error", s);
    }

    free(chStr);
    p.close();
}
