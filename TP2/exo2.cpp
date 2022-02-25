#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
    Array& result=w->newArray(toSort.size());


	// insertion sort from toSort to sorted
    int i;
    result[0]=toSort[0];
    for (int n = 1; n < toSort.size(); ++n) {
        if(toSort[n] < result[n-1] ){
            i = n-1;
            while(i >= 0 && toSort[n] < result[i]){
                result[i+1] = result[i];
                i--;
            }
            result[i+1] = toSort[n];
        }
        else{
            result[n] = toSort[n];
        }
    }
	
    toSort=result; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
