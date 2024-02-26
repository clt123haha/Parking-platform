#include "loginview.h"
#include "ui_loginview.h"

#include <QMessageBox>


LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    v = new verify(this);
    mainView = new MainWindow;
    enrollView = new EnrollView;
    v->setGeometry(250,200,180,80);
    ui->lineEdit->setPlaceholderText("长度6-8位");
    ui->lineEdit_2->setPlaceholderText("长度6-10位");
    myConneet = conneet::getmyconneet();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    cansee  = false;
    connect(enrollView,SIGNAL(back2LoginView()),this,SLOT(cancelEnroll()));
    connect(mainView,SIGNAL(back2Login()),this,SLOT(backtoLogin()));
    connect(ReadThread::getReadThread(),SIGNAL(sendRcv(int,char*,int)),this,SLOT(getRes(int,char*,int)));
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(this,"提示信息","用户名或密码为空");
        return;
    }

    if(v->code.toLower() != ui->lineEdit_3->text().toLower())
    {
        QMessageBox::information(this,"提示信息","验证码错误");
        return;
    }

    QRegularExpression regex("^[@#￥]");
    if(regex.match(ui->lineEdit->text()).hasMatch() || regex.match(ui->lineEdit_2->text()).hasMatch())
    {
        QMessageBox::information(this,"提示信息","不可包含特殊字符");
        return;
    }

    if(!(ui->lineEdit->text().length()>=6 && ui->lineEdit->text().length() <=8 && ui->lineEdit_2->text().length()>=6 && ui->lineEdit_2->text().length() <=10 ))
    {
        QMessageBox::information(this,"提示信息","用户名或密码长度不符合规定");
        return;
    }

    QString MD5;
    QByteArray  str =  QCryptographicHash::hash(ui->lineEdit_2->text().toLatin1(),QCryptographicHash::Md5);
    MD5.append(str.toHex());

    //发送服务器
    WriteThread::getWriteThread()->sendLogin(ui->lineEdit->text(),MD5);
}

void LoginView::getRes(int flag,char meg[],int whichView)
{
    if(whichView == 1)
    {
        if(flag == 1)
        {
            this->hide();
            mainView->show();
            mainView->setId(meg);
            mainView->ReadyWork();
            mainView->openTimer();
        }else if(flag == 0)
        {
            QMessageBox::information(this,"提示信息","账号或密码错误");
            qDebug() << meg;
            return;
        }else if(flag == -1)
        {
            QMessageBox::information(this,"提示信息",meg);
            return;
        }
    }
}

void LoginView::cancelEnroll()
{
    enrollView->hide();
    this->show();
}

void LoginView::on_pushButton_2_clicked()
{
    enrollView->show();
    this->hide();
}

void LoginView::backtoLogin()
{
    mainView->hide();
    this->show();
}

void LoginView::on_pushButton_3_clicked()
{
    if(cansee)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }

    cansee  = !cansee;
}
