#ifndef DRONEMANAGER_H
#define DRONEMANAGER_H

#include "drone.h"
#include "tileManager.h"
class DroneManager
{
public:
    DroneManager(TileManager *tileManager);
    void calculateinWindowPosition(long double latitude,long double longitude,Drone *drone);
    void initializeNewDrone(QWidget *parent, bool isEnemy,QHBoxLayout *layout);
    void refreshDronePositions();
    QVector<Drone*> *drones;
private:
    TileManager *tileManager;
};

#endif // DRONEMANAGER_H
