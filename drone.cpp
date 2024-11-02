#include "drone.h"
#include <QPixmap>
#include <QDir>

Drone::Drone(QWidget *window, TileManager *tileManager) : QLabel(window) {
    this->tileManager = tileManager;
    if(!this->isEnemy){
        QDir mydir = QDir::currentPath();
        mydir.cdUp();
        mydir.cdUp();
        QString path = mydir.absolutePath();
        qDebug()<< path;
        this->droneImageSize.setHeight(25);
        this->droneImageSize.setWidth(25);
        QImage droneImage(path+"/drone.png");
        QImage resizedDroneImage = droneImage.scaled(this->droneImageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        qDebug() << droneImage.size();
        this->setParent(window);
        this->setPixmap(QPixmap::fromImage(resizedDroneImage));
    }
}

void Drone::calculateinWindowPosition(long double latitude,long double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
    const double radius = 6371.5;
    long double radianLatitudeDrone = M_PI * this->latitude/180;
    long double radianLongitudeDrone = M_PI * this->longitude/180;
    long double radianLatitudeMap = M_PI * this->tileManager->latitude/180;
    long double radianLongitudeMap = M_PI * this->tileManager->longitude/180;
    this->realDistanceY = radius  * (long double)(radianLatitudeMap-radianLatitudeDrone)*1000;
    this->realDistanceX = radius * std::cos(radianLongitudeDrone) * (long double)(radianLongitudeMap-radianLongitudeDrone)*1000;
    qDebug() << "realdistance x: " << realDistanceX << " realdistance Y: " << realDistanceY;
    qDebug()<< "eachTileRealDistance: " << this->tileManager->calculateEachTileRealDistance();
    double eachPixel = 250/this->tileManager->calculateEachTileRealDistance();
    qDebug()<<eachPixel;
    this->locationX = -eachPixel*realDistanceX;
    this->locationY = eachPixel*realDistanceY;
    qDebug() << "location x: " << locationX << " location y: " << locationY;
}
void Drone::moveLocation(){
    //this->move(this->locationY,this->locationX);
    this->move(0,-250);
}
void Drone::setCoordinates(long double latitude,long double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}

double Drone::getCoordinates(){
    long double coordinates[2] = {this->latitude,this->longitude};
    return *coordinates;
}
