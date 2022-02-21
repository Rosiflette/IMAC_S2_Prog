#include <iostream>

using namespace std;

long power(long value, long n)
{
    if(n == 1){
        return value;
    }
    return power(value, n-1)*value; 
}

int main(int argc, char *argv[])
{
    long val = power(3, 4);
    cout << "La valeur est : " <<val<< endl;
    return 0;
}
