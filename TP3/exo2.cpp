#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;



/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	// do not use increments, use two different binary search loop
    int start = 0;
    int end = array.size();

    while(start < end){
        int milieu = (start +end)/2;
        if(toSearch > array[milieu]){
            start = milieu +1;
        }
        else if(toSearch < array[milieu]){
            end = milieu;
        }
        else{
            indexMin = milieu;
            indexMax = milieu;
            end = milieu;
        }
    }

    start = (0 +array.size())/2;
    end = array.size();
    while(start < end){
        int milieu = (start +end)/2;
        if(toSearch > array[milieu]){
            start = milieu +1;
        }
        else if(toSearch < array[milieu]){
            end = milieu;
        }
        else{
            indexMax = milieu;
            start = milieu+1;
        }
    }

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
