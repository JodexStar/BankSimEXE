#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "insertcard.h"
#include "rfidll.h"

enum state {showcard, MainUi};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
