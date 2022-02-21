#include <iostream>

using namespace std;

int search(int value, int array[], int size)
{
    if(size < 0){
        return size;
    }
    if(array[size]==value){
        return size;
    }
    return search(value, array, --size);

}

int main(int argc, char *argv[])
{
    int tab[6] = {1,2,8,6,3,9};
    int val = search(12, tab, 6);
    cout << "L'indice est : " <<  val << endl;
}




