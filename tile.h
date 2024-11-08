#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QLabel>
class Tile : public QLabel {
    Q_OBJECT

public:
    explicit Tile(QWidget *parent = nullptr,int x =0,int y=0,int zoom = 15);
    virtual ~Tile();
    void loadMap(int x,int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onMapDownloaded(QNetworkReply *reply);
    void refreshMap();
private:
    QTimer *refreshTimer;
    QPixmap mapImage;
    int x;
    int y;
    int zoom;
    QNetworkAccessManager *networkManager;
};

#endif // TILE_H
