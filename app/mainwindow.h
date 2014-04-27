#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "feedaengine.h"
#include "constants.h"

namespace Ui {
class MainWindow;
}

using namespace Core;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    FeedaEngine *mEngine;
};

#endif // MAINWINDOW_H
