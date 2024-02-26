#include "enrollview.h"
#include "ui_enrollview.h"

#include <QMessageBox>

EnrollView::EnrollView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnrollView)
{
    ui->setupUi(this);
    cansee1 = cansee2 = false;
    connect(ReadThread::getReadThread(),SIGNAL(sendRcv(int,char*,int)),this,SLOT(getRuslt(int,char*,int)));
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("长度6-8位");
    ui->lineEdit_2->setPlaceholderText("长度6-8位");
    ui->lineEdit_3->setPlaceholderText("长度6-10位");
    ui->lineEdit_4->setPlaceholderText("长度6-10位");
}

EnrollView::~EnrollView()
{
    delete ui;
}

void EnrollView::on_pushButton_clicked()
{

    QRegularExpression regex("^[a-zA-Z0-9_]");
    if(!regex.match(ui->lineEdit->text()).hasMatch())
    {
        QMessageBox::information(this,"提示信息","账号只能包含字母数字下划线");
        return;
    }

    QRegularExpression regex2("^(?![\\p{P}\\p{S}])[\u4e00-\u9fa5a-zA-Z0-9]+$");
    if(!regex2.match(ui->lineEdit_2->text()).hasMatch())
    {
        QMessageBox::information(this,"提示信息","用户名只能包含中英文和数字");
        return;
    }

    QRegularExpression regex3("^[a-zA-Z0-9_]");
    if(!regex3.match(ui->lineEdit_3->text()).hasMatch() || !regex3.match(ui->lineEdit_4->text()).hasMatch())
    {
        QMessageBox::information(this,"提示信息","密码只能包含字母数字下划线");
        return;
    }

    if(!(ui->lineEdit->text().length() >=6 &&
         ui->lineEdit_2->text().length() >=6 &&
         ui->lineEdit_3->text().length() >=6 &&
         ui->lineEdit_4->text().length() >=6 &&
         ui->lineEdit->text().length() <=8 &&
         ui->lineEdit_2->text().length() <=8 &&
         ui->lineEdit_3->text().length() <=10 &&
         ui->lineEdit_4->text().length() <= 10))
    {
        QMessageBox::information(this,"提示信息","长度不符合要求");
        return;
    }

    QString MD5;
    QByteArray  str =  QCryptographicHash::hash(ui->lineEdit_3->text().toLatin1(),QCryptographicHash::Md5);
    MD5.append(str.toHex());

    WriteThread::getWriteThread()->sendEnroll(ui->lineEdit->text(),ui->lineEdit_2->text(),MD5);
}

void EnrollView::on_pushButton_2_clicked()
{
    emit back2LoginView();
}

void EnrollView::on_pushButton_3_clicked()
{
    if(cansee1)
    {
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }else
    {
        ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    }

    cansee1  = !cansee1;
}

void EnrollView::on_pushButton_4_clicked()
{
    if(cansee2)
    {
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    }else
    {
        ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
    }

    cansee2  = !cansee2;
}

void EnrollView::getRuslt(int flag, char *mes,int whichView)
{
    if(whichView == 2)
    {
        if(flag == 1)
        {
            emit back2LoginView();
        }else if(flag == 0)
        {
            QMessageBox::information(this,"提示信息","状态错误");
            qDebug() << mes;
            return;
        }else if(flag == -1)
        {
            QMessageBox::information(this,"提示信息",mes);
            return;
        }
    }
}
