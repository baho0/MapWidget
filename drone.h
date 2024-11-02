#ifndef DRONE_H
#define DRONE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>

class Drone: public QLabel
{
    Q_OBJECT
public:
    Drone(QWidget *window,bool isEnemy);
    bool isEnemy = false;
    long double latitude;
    long double longitude;
    void setCoordinates(long double latitude,long double longitude);
    double getCoordinates();
    void setCoordinatesWithMavlink();
    void setSize(QSize size);
    QSize getSize();
private:
    QSize droneImageSize = QSize(25,25);
};

#endif // DRONE_H
