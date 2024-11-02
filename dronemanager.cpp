#include "dronemanager.h"
#include <QLabel>


DroneManager::DroneManager(TileManager *tileManager) {
    this->tileManager = tileManager;
    this->drones= new QVector<Drone*>();
}

void DroneManager::initializeNewDrone(QWidget *parent, bool isEnemy,QHBoxLayout *layout){
    Drone *drone = new Drone(parent,isEnemy);
    layout->addWidget(drone);
    drones->append(drone);
}

void DroneManager::calculateinWindowPosition(long double latitude,long double longitude,Drone *drone){
    drone->latitude = latitude;
    drone->longitude = longitude;
    const double radius = 6371.5;
    long double radianLatitudeDrone = M_PI * drone->latitude/180;
    long double radianLongitudeDrone = M_PI * drone->longitude/180;
    long double radianLatitudeMap = M_PI * this->tileManager->latitude/180;
    long double radianLongitudeMap = M_PI * this->tileManager->longitude/180;
    double realDistanceY = radius  * (long double)(radianLatitudeMap-radianLatitudeDrone)*1000;
    double realDistanceX = radius * std::cos(radianLongitudeDrone) * (long double)(radianLongitudeMap-radianLongitudeDrone)*1000;
    qDebug()<< "eachTileRealDistance: " << this->tileManager->calculateEachTileRealDistance();
    double eachPixel = 250/this->tileManager->calculateEachTileRealDistance();
    qDebug()<<eachPixel;
    drone->setGeometry(-eachPixel*realDistanceX,eachPixel*realDistanceY,25,25);
}

void DroneManager::refreshDronePositions(){
    for(Drone *drone : *this->drones){
        drone->setCoordinatesWithMavlink();
        //calculateinWindowPosition(drone->latitude,drone->longitude,drone);
        calculateinWindowPosition(39.920756,32.854052,drone);

    }
}

