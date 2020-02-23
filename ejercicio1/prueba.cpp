#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

int main(){
    int a=5;
    int numero;    
    numero = rand() % 10;
    
    cout<<numero<<typeid(numero).name()<< endl;



    return 0;
}