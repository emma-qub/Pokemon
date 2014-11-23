#include "MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent) {

  m_scene = new QGraphicsScene(this);
  m_view = new QGraphicsView(m_scene);
  m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  QPixmap map("../Pokemon/resources/PokemonMaps/Pallet_Town_GSC.png", 0, Qt::AutoColor);

  m_item = m_scene->addPixmap(map);
  m_item->setScale(2);
  m_item->setPos(50, 50);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addWidget(m_view);
  setLayout(mainLayout);

  setFixedSize(400, 300);

  qDebug() << children();
}
