#include "tileManager.h"
#include "tile.h"
#include <QGridLayout>
#include <QDebug>

TileManager::TileManager(int countOfTilesX,int countOfTilesY,QGridLayout *gridLayout,long double latitude,long double longitude,int zoom) {
    // Construct the URL for the OpenStreetMap tile (example for zoom level 12)
    this->gridLayout = gridLayout;
    this->zoom = zoom;
    this->latitude = latitude;
    this->longitude = longitude;
    this->countOfTilesX = countOfTilesX;
    this->countOfTilesY = countOfTilesY;
    calculateCoordinates(latitude,longitude);
}
TileManager::~TileManager()=default;
void TileManager::setZoom(int zoom,bool zoomState){
    if(zoomState){
        if(this->zoom != 19){
            this->zoom = zoom;

        }
    }else{
        if(this->zoom != 1){
            this->zoom = zoom;
        }
    }
    calculateCoordinates(this->latitude,this->longitude);
}

int TileManager::getZoom(){
    return this->zoom;
}

void TileManager::deleteTiles(){
    while (QLayoutItem* tile = gridLayout->takeAt(0)) {
        if (QWidget* widget = tile->widget()) {
            widget->deleteLater();
        }
        delete tile;
    }
}

void TileManager::calculateNewCoordinates(int x,int y,int zoom){
    this->longitude = ((x+this->xIncrement) * 360.0 / (1 << zoom)) - 180;
    long double n = M_PI - (2.0 * M_PI * y+this->yIncrement) / (1 << zoom);
    this->latitude = (180.0 / M_PI) * atan(sinh(n));
}
double TileManager::calculateEachTileRealDistance(){
    long double coordinateDiff = ((2 * 360.0 / (1 << zoom)) - 180)-((1 * 360.0 / (1 << this->zoom)) - 180);
    //qDebug() << coordinateDiff;
    double realDistance = (coordinateDiff*40075)/360*1000;
    return realDistance;
}
void TileManager::calculateCoordinates(long double latitude,long double longitude){
    this->x = static_cast<int>(floor((longitude + 180) / 360 * (1 << zoom)));
    this->y = static_cast<int>(floor((1 - (log(tan(latitude * M_PI / 180) + 1 / cos(latitude * M_PI / 180)) / M_PI)) / 2 * (1 << zoom)));
}

void TileManager::designTheLayout(QObject *parent){
    for(int x=0;x<countOfTilesX;x++){
        for(int y=0;y<countOfTilesY;y++){
            Tile *map=new Tile(nullptr,this->x+x+this->xIncrement,this->y+y+this->yIncrement,this->zoom);
            map->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            map->setFixedSize(250,250);
            //map->loadMap(this->x+x,this->y+y);
            map->show();
            this->gridLayout->addWidget(map,y,x);
        }
    }
}

