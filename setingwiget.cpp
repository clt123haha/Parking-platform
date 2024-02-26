#include "setingwiget.h"
#include "ui_setingwiget.h"

SetingWiget::SetingWiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetingWiget)
{
    isMain = false;
    ui->setupUi(this);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
}

SetingWiget::~SetingWiget()
{
    delete ui;
}

void SetingWiget::getSetting2Widget()
{
    getSetting::getmyseting()->readSet();
    ui->lineEdit->setText(getSetting::getmyseting()->getIp());
    ui->lineEdit_2->setText(QString::number(getSetting::getmyseting()->getPort()));
    ui->lineEdit_3->setText(getSetting::getmyseting()->getImgPath());
    ui->lineEdit_4->setText(getSetting::getmyseting()->getVideoPath());
    ui->lineEdit_5->setText(QString::number(getSetting::getmyseting()->getSize()));
}

void SetingWiget::on_pushButton_3_clicked()
{
    ui->lineEdit_3->setText(QFileDialog::getExistingDirectory(NULL,"车牌图片保存路径","."));
}

void SetingWiget::on_pushButton_4_clicked()
{
    ui->lineEdit_4->setText(QFileDialog::getExistingDirectory(NULL,"视频录制保存路径","."));
}

void SetingWiget::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty() ||
       ui->lineEdit_2->text().isEmpty() ||
       ui->lineEdit_3->text().isEmpty() ||
       ui->lineEdit_4->text().isEmpty() ||
      ui->lineEdit_5->text().isEmpty())
    {
        QMessageBox::information(this,"提示信息","信息缺漏");
        return;
    }
    fstream f;
    f.open("setting.txt", ios::out | ios::trunc);
    f << ui->lineEdit->text().toStdString().c_str() << endl;
    f << ui->lineEdit_2->text().toStdString().c_str() << endl;
    f << ui->lineEdit_3->text().toStdString().c_str() << endl;
    f << ui->lineEdit_4->text().toStdString().c_str() << endl;
    f << ui->lineEdit_5->text().toStdString().c_str() << endl;
    f.close();
    QMessageBox::information(this,"提示信息","设置完成");

    if(!isMain)
    {
        if(!conneet::getmyconneet()->Conneet(ui->lineEdit->text().toStdString().c_str(),ui->lineEdit_2->text().toInt()))
        {
            QMessageBox::information(this,"提示信息","连接失败");
            return;
        }
    }

    emit setEnd();
}

void SetingWiget::on_pushButton_2_clicked()
{
    emit setCancel();
}

void SetingWiget::setIsMain(bool value)
{
    isMain = value;
}
