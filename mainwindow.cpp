#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJSEngine>
#include <QJSValue>
#include <QDebug>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->btnadd, &QPushButton::released, this, &MainWindow::on_btnadd_clicked);
    connect(ui->btnsub, &QPushButton::released, this, &MainWindow::on_btnsub_clicked);
    connect(ui->btnmultiple, &QPushButton::released, this, &MainWindow::on_btnmultiple_clicked);
    connect(ui->btndivide, &QPushButton::released, this, &MainWindow::on_btndivide_clicked);
    connect(ui->btnanswer, &QPushButton::released, this, &MainWindow::on_btnanswer_clicked);

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::on_pushButton_clicked); // 9
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::on_pushButton_9_clicked); // 1
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::on_pushButton_6_clicked); // 2
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::on_pushButton_3_clicked); // 3
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::on_pushButton_8_clicked); // 4
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::on_pushButton_5_clicked); // 5
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::on_pushButton_2_clicked); // 6
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::on_pushButton_7_clicked); // 7
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::on_pushButton_4_clicked); // 8

    connect(ui->pushButton_11, &QPushButton::released, this, &MainWindow::on_pushButton_11_clicked); // 0
    connect(ui->pushButton_10, &QPushButton::released, this, &MainWindow::on_pushButton_10_clicked); // AC
    connect(ui->pushButton_12, &QPushButton::released, this, &MainWindow::on_pushButton_12_clicked); // +/-
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btndivide_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    QString buttonText = ui->btndivide->text();
    ui->lineEdit_2->setText(currentText + buttonText);
}

void MainWindow::on_btnmultiple_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    QString buttonText = ui->btnmultiple->text();
    ui->lineEdit_2->setText(currentText + buttonText);
}

void MainWindow::on_btnadd_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    QString buttonText = ui->btnadd->text();
    ui->lineEdit_2->setText(currentText + buttonText);
}

void MainWindow::on_btnsub_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    QString buttonText = ui->btnsub->text();
    ui->lineEdit_2->setText(currentText + buttonText);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_11_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    ui->lineEdit_2->setText(currentText + "0");
}

void MainWindow::on_pushButton_12_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    if (currentText.isEmpty())
        return;

    if (currentText.at(0) == '-')
        currentText.remove(0, 1);
    else
        currentText.prepend('-');

    ui->lineEdit_2->setText(currentText);
}

void MainWindow::on_btnanswer_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    qDebug() << "Evaluating expression:" << currentText;
    QString result = QString::number(evalExpression(currentText));
    qDebug() << "Result:" << result;
    ui->lineEdit_2->setText(result);
}

double MainWindow::evalExpression(const QString &expression)
{
    QString sanitizedExpression = expression.trimmed();

    // Validate the expression format using QRegularExpression
    QRegularExpression re("^[0-9\\+\\-\\*/\\(\\)\\s]+$");
    QRegularExpressionMatch match = re.match(sanitizedExpression);

    if (!match.hasMatch() || sanitizedExpression.isEmpty())
    {
        qWarning() << "Invalid expression:" << sanitizedExpression;
        return 0.0;
    }

    // Replace any potential invalid characters or sequences
    sanitizedExpression = sanitizedExpression.replace(QRegularExpression("\\s+"), ""); // Remove extra spaces

    // Normalize multiple plus signs, minus signs, etc.
    sanitizedExpression = sanitizedExpression.replace(QRegularExpression("\\++"), "+"); // Normalize multiple plus signs
    sanitizedExpression = sanitizedExpression.replace(QRegularExpression("\\*\\*"), "*"); // Normalize double asterisks
    sanitizedExpression = sanitizedExpression.replace(QRegularExpression("\\/\\/+"), "/"); // Normalize double slashes

    // Remove leading and trailing operators if any
    if (sanitizedExpression.startsWith("+") || sanitizedExpression.startsWith("-") ||
        sanitizedExpression.startsWith("*") || sanitizedExpression.startsWith("/"))
    {
        sanitizedExpression.remove(0, 1);
    }
    if (sanitizedExpression.endsWith("+") || sanitizedExpression.endsWith("-") ||
        sanitizedExpression.endsWith("*") || sanitizedExpression.endsWith("/"))
    {
        sanitizedExpression.chop(1); // Remove trailing operator
    }

    qDebug() << "Original expression:" << expression;
    qDebug() << "Sanitized expression:" << sanitizedExpression;
    qDebug() << "Evaluating expression:" << sanitizedExpression;

    // Evaluate the expression
    QJSEngine engine;
    QJSValue result = engine.evaluate(sanitizedExpression);

    if (result.isError())
    {
        qWarning() << "Error evaluating expression:" << result.toString();
        return 0.0;
    }

    return result.toNumber();
}

void MainWindow::on_pushButton_9_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "1"); }
void MainWindow::on_pushButton_6_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "2"); }
void MainWindow::on_pushButton_3_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "3"); }
void MainWindow::on_pushButton_8_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "4"); }
void MainWindow::on_pushButton_5_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "5");}
void MainWindow::on_pushButton_2_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "6"); }
void MainWindow::on_pushButton_7_clicked()
{
    QString currentText = ui->lineEdit_2->text();
    qDebug() << "Button 7 clicked. Current text:" << currentText;
    ui->lineEdit_2->setText(currentText + "7");
}

void MainWindow::on_pushButton_4_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "8"); }
void MainWindow::on_pushButton_clicked() { ui->lineEdit_2->setText(ui->lineEdit_2->text() + "9"); }
