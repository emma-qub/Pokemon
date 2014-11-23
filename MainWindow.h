#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = 0);

private:
  QGraphicsView* m_view;
  QGraphicsScene* m_scene;
  QGraphicsItem* m_item;

signals:

public slots:

};

#endif // MAINWINDOW_H
