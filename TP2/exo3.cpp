#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort

    int tamp;
    for (int i = 1; i < toSort.size(); ++i) {
        for (int k = 0; k < toSort.size()-1; ++k) {
            if(toSort[k]>toSort[k+1]){
                tamp = toSort[k];
                toSort[k] = toSort[k+1];
                toSort[k+1] = tamp;

            }
        }

    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
