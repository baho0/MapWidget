#ifndef DRONEMANAGER_H
#define DRONEMANAGER_H

#include "drone.h"
#include "tileManager.h"
class DroneManager
{
public:
    DroneManager();
    void calculateinWindowPosition(long double latitude,long double longitude,Drone *drone);
    void initializeNewDrone(QWidget *parent,TileManager *tileManager, bool isEnemy,QHBoxLayout *layout);
    void moveLocation(Drone *drone);
    void refreshDronePositions();
    QVector<Drone*> *drones;
private:

};

#endif // DRONEMANAGER_H
