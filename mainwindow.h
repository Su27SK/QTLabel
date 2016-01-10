#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <QTextEdit>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateLabel();
    void repaintLabel();
    void showLabel();
    ~MainWindow();
 public slots:
       void setLabelText(QString message);
       void delayShowLabel();
private:
    Ui::MainWindow *ui;
    QLabel* label;
    QString _message;
    //QApplication* qApp;
};

class myThread :public QThread
{
    Q_OBJECT

    public:
          myThread(string message);
          void showMessage(string message);
          void fakeMain();
          string ItoString(int source);
          virtual void run();
     signals:
          void signalGUI(QString sTriggleLog);
     private:
        QString _message;
        QTextEdit   m_qeLog;
};

#endif // MAINWINDOW_H
