#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
    int ind;
    int min;
    for (int i = 0; i< toSort.size(); i++) {
        ind = i;
        min = toSort[i];
        for(int k = i; k < toSort.size(); k++){
            if(toSort[k]<min){
                ind = k;
                min = toSort[ind];
            }
        }
        toSort[ind] = toSort[i];
        toSort[i] = min;

    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
