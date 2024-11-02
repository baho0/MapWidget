#include "drone.h"
#include <QPixmap>
#include <QDir>

Drone::Drone(QWidget *widget,bool isEnemy) : QLabel(widget) {
    QImage resizedDroneImage;
    QDir mydir = QDir::currentPath();
    mydir.cdUp();
    mydir.cdUp();
    QString path = mydir.absolutePath();
    qDebug()<< path;
    this->droneImageSize.setHeight(this->droneImageSize.height());
    this->droneImageSize.setWidth(this->droneImageSize.width());
    this->resize(this->droneImageSize.width(),this->droneImageSize.height());
    qDebug() << "size: " << this->size().width() << " " << this->size().height();
    if(!this->isEnemy){
        QImage droneImage(path+"/drone.png");
        resizedDroneImage = droneImage.scaled(this->droneImageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        qDebug() << droneImage.size();
    }else{
        QImage droneImage(path+"/enemyDrone.png");
        resizedDroneImage = droneImage.scaled(this->droneImageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        qDebug() << droneImage.size();
    }
    this->setParent(widget);
    this->setPixmap(QPixmap::fromImage(resizedDroneImage));
}


void Drone::setCoordinatesWithMavlink(){

}

void Drone::setCoordinates(long double latitude,long double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}

double Drone::getCoordinates(){
    long double coordinates[2] = {this->latitude,this->longitude};
    return *coordinates;
}
