#ifndef TILEMANAGER_H
#define TILEMANAGER_H
#include <QGridLayout>
#include <QKeyEvent>

class TileManager
{
public:
    TileManager(int countOfTilesX,int countOfTilesY,QGridLayout *gridLayout,long double latitude,long double longitude,int zoom);
    void designTheLayout(QObject *parent = nullptr);
    virtual ~TileManager();
    int x;
    int y;

    long double latitude,longitude;
    QGridLayout *gridLayout;
    void setZoom(int zoom,bool zoomState);
    void calculateCoordinates(long double latitude,long double longitude);
    int xIncrement= 0;
    int yIncrement =0;
    bool zoomState; //zoomIn = true zoomOut = false
    void deleteTiles();
    int getZoom();
    void calculateNewCoordinates(int x,int y,int zoom);
    double calculateEachTileRealDistance();
    int countOfTilesX;
    int countOfTilesY;
private:

    int zoom;

};

#endif // TILEMANAGER_H
