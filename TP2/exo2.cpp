#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
    Array& result=w->newArray(toSort.size());


	// insertion sort from toSort to sorted

//    result[0] = toSort[0];
//    for (int n = 1; n < toSort.size(); ++n) {
//        //printf(" hellllllllllllllllllllllloooooooooooooooooooo %d \n", result[result.size()]);
//        if(toSort[n] < result[result.size()-1] ){
//            int i = result.size();
//            while(i > 0 && toSort[n] < result[i-1]){
//                result[i] = result[i-1];
//                i--;
//            }
//            result[i] = toSort[n];
//        }
//        else{
//            result[result.size()] = toSort[n];
//        }
//    }
	
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
