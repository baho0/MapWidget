#ifndef DRONE_H
#define DRONE_H
#include "tileManager.h"
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>

class Drone: public QLabel
{
    Q_OBJECT
public:
    Drone(QWidget *window,TileManager *tileManager,bool isEnemy);
    bool isEnemy = false;
    long double latitude;
    long double longitude;
    void setCoordinates(long double latitude,long double longitude);
    double getCoordinates();
    void setCoordinatesWithMavlink();
    TileManager *tileManager;
    void setLocation(const char xOrY, double value);
    double getLocation(const char xOrY);
    void setSize(QSize size);
    QSize getSize();
private:
    double locationX,locationY;
    QSize droneImageSize = QSize(25,25);
};

#endif // DRONE_H
