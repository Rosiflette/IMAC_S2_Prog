#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

Array& merge(Array& first, Array& second);

Array& splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if(origin.size() == 1){
        return origin;
    }

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
    // split

    for (int i = 0; i<first.size();i++) {
        first[i] = origin[i];
    }
    for(int i = 0; i < second.size(); i++){
        second[i] = origin[i+first.size()];
    }

    first = splitAndMerge(first);
    second = splitAndMerge(second);

    return merge(first, second);



}

Array& merge(Array& first, Array& second)
{
    Array& result = w->newArray(first.size()+second.size());

    int i = 0;
    int j = 0;

    while(i < first.size() && j < second.size()){
        if(first[i]<second[j]){
            result[i+j] = first[i];
            i++;
        }
        else{
            result[i+j] = second[j];
            j++;
        }

    }

    while(i< first.size()){
        result[i+j] = first[i];
        i++;
    }

    while(j<second.size()){
        result[i+j] = second[j];
        j++;
    }

    return result;

}

void mergeSort(Array& toSort)
{
    toSort = splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
