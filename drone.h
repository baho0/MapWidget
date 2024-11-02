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
    Drone(QWidget *window,TileManager *tileManager);
    bool isEnemy = false;
    void setCoordinates(long double latitude,long double longitude);
    double getCoordinates();
    void calculateinWindowPosition(long double latitude,long double longitude);
    double locationX,locationY;
    void moveLocation();
private:
    QSize droneImageSize;
    TileManager *tileManager;
    long double latitude;
    long double longitude;
    double realDistanceX;
    double realDistanceY;
};

#endif // DRONE_H
