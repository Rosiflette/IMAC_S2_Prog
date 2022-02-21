#include <iostream>

using namespace std;

void allEvens(int evens[], int array[], int evenSize, int arraySize)
{
    if(arraySize >= 0){
        
        if(array[arraySize]%2 == 0){
            evens[evenSize] = array[arraySize];
            evenSize++;
        }

        allEvens(evens, array, evenSize, --arraySize);


    }

}

int main(int argc, char *argv[])
{
    int tailleTab = 6;
    int tab[tailleTab] = {2,2,8,6,12,4};
    int paire[tailleTab] = {0,0,0,0,0,0};

    allEvens(paire, tab, 0, tailleTab-1);

    for(int i =0; i<tailleTab; i++){
        cout << "indice :" << i << " val : " << paire[i] << endl;
    }
    return 0;
}




