#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    Point k;
    if(n==0){
        return 0;
    }
    k.x = pow(z.x, 2) - pow(z.y, 2) + point.x;
    k.y = 2 * z.x * z.y + point.y;

    if(z.length()<2){
        return isMandelbrot(k, n-1, point);
    }
    else{
        return n;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



