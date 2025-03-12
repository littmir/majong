#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qobjectdefs.h>
#include <qwidget.h>

class QGridLayout;

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow();

private:
  QGridLayout *grid_ = nullptr;
};
#endif // MAINWINDOW_H
