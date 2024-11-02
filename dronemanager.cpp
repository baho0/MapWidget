#include "dronemanager.h"
#include <QLabel>


DroneManager::DroneManager() {
    this->drones= new QVector<Drone*>();
}

void DroneManager::initializeNewDrone(QWidget *parent,TileManager *tileManager, bool isEnemy,QHBoxLayout *layout){
    Drone *drone = new Drone(parent,tileManager,isEnemy);
    layout->addWidget(drone);
    drones->append(drone);
}

void DroneManager::calculateinWindowPosition(long double latitude,long double longitude,Drone *drone){
    drone->latitude = latitude;
    drone->longitude = longitude;
    const double radius = 6371.5;
    long double radianLatitudeDrone = M_PI * drone->latitude/180;
    long double radianLongitudeDrone = M_PI * drone->longitude/180;
    long double radianLatitudeMap = M_PI * drone->tileManager->latitude/180;
    long double radianLongitudeMap = M_PI * drone->tileManager->longitude/180;
    double realDistanceY = radius  * (long double)(radianLatitudeMap-radianLatitudeDrone)*1000;
    double realDistanceX = radius * std::cos(radianLongitudeDrone) * (long double)(radianLongitudeMap-radianLongitudeDrone)*1000;
    qDebug()<< "eachTileRealDistance: " << drone->tileManager->calculateEachTileRealDistance();
    double eachPixel = 250/drone->tileManager->calculateEachTileRealDistance();
    qDebug()<<eachPixel;
    drone->setLocation('X',-eachPixel*realDistanceX);
    drone->setLocation('Y',eachPixel*realDistanceY);
}

void DroneManager::refreshDronePositions(){
    for(Drone *drone : *this->drones){
        drone->setCoordinatesWithMavlink();
        //calculateinWindowPosition(drone->latitude,drone->longitude,drone);
        calculateinWindowPosition(39.91932273771436, 32.852279661147364,drone);
        moveLocation(drone);
    }
}
void DroneManager::moveLocation(Drone *drone){
    drone->setGeometry(drone->getLocation('X')+25/2,drone->getLocation('Y')+25/2,25,25);
}
