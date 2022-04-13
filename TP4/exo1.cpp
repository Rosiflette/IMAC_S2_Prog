#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


int Heap::leftChild(int nodeIndex)
{
    return 2*nodeIndex+1;
}

int Heap::rightChild(int nodeIndex)
{
    return 2*nodeIndex+2;
}


void Heap::insertHeapNode(int heapSize, int value)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    int i = heapSize;
    (*this)[i] = value;

    while(i>0 && this->get(i) > this->get((i-1)/2)){ // (i-1)/2 = au parent
        this->swap(i, (i-1)/2);
        i = ((i-1)/2);
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    int i_max = nodeIndex;
    if(this->leftChild(nodeIndex) < heapSize && this->get(i_max) < this->get(this->leftChild(nodeIndex))){
        i_max = this->leftChild(nodeIndex);
    }
    if(this->rightChild(nodeIndex) < heapSize && this->get(i_max) < this->get(this->rightChild(nodeIndex))){
        i_max = this->rightChild(nodeIndex);
    }
    if(i_max != nodeIndex){
        this->swap(nodeIndex, i_max);
        this->heapify(heapSize, i_max);
    }

}

void Heap::buildHeap(Array& numbers)
{
    for(int i = 0; i < numbers.size(); i++){
        this->insertHeapNode(numbers[i], this->size());
    }


}

void Heap::heapSort()
{
    for (int i = (this->size()-1); i > 0; i--) {
        this->swap(0, i);
        this->heapify(i, 0);
    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
    w->show();

    return a.exec();
}
