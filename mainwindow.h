#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnadd_clicked();
    void on_btnsub_clicked();
    void on_btnmultiple_clicked();
    void on_btndivide_clicked();
    void on_btnanswer_clicked();
    void on_pushButton_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;

    void updateDisplay(const QString &text);
    void handleMathOperation(const QString &operation);
    void evaluateExpression();
    double evalExpression(const QString &expression); // Ensure this is declared here
    double calcVal;
    bool addTrigger;
    bool subTrigger;
    bool multTrigger;
    bool divTrigger;
};

#endif // MAINWINDOW_H
