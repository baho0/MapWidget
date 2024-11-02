#include "tile.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
Tile::Tile(QWidget *parent,int x,int y,int zoom)
    : QLabel(parent), networkManager(new QNetworkAccessManager(this)) {
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &Tile::onMapDownloaded);
    this->zoom = zoom;
    loadMap(x, y);
}


void Tile::loadMap(int x,int y) {
    QString urlString = QString("https://tile.openstreetmap.org/%1/%2/%3.png").arg(zoom).arg(x).arg(y);
    QNetworkRequest request(urlString);
    request.setRawHeader("User-Agent", "MyCustomMapApp/1.0");
    QNetworkReply *reply = networkManager->get(request);
}

Tile::~Tile()=default;
void Tile::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (!mapImage.isNull()) {
        painter.drawPixmap(0, 0, mapImage);
    }
}
void Tile::refreshMap(){
    loadMap(x,y);
}
void Tile::onMapDownloaded(QNetworkReply *reply) {
    QByteArray imageData = reply->readAll();
    QImage mapImage;
    if (reply->error() == QNetworkReply::NoError) {
        if (mapImage.loadFromData(imageData)) {
            QSize newSize(250, 250);
            QImage resizedMapImage = mapImage.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            QLabel *mapLabel = new QLabel(this);
            mapLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            mapLabel->setPixmap(QPixmap::fromImage(resizedMapImage));
            mapLabel->show();
            update();
        } else {
            qDebug() << "Failed to load map image from data.";
        }
    } else {
        qDebug() << "Error downloading map:" << reply->errorString();
    }
    reply->deleteLater();
}



