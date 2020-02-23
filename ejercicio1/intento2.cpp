#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <time.h>

using namespace std;


vector<vector<int>> v3;

vector<vector<int>> llenarMatrizAleatorios(int size){
    vector<int> v1;
    vector<vector<int>> v2;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            v1.push_back((int)(rand() % 20));
        }
        v2.push_back(v1);
        v1.erase(v1.begin(), v1.begin()+size);
    }

    return v2;
}

vector<vector<int>> llenarMatrizCeros(int size){
    vector<int> v1;
    vector<vector<int>> v2;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            v1.push_back(0);
        }
        v2.push_back(v1);
        v1.erase(v1.begin(), v1.begin()+size);
    }

    return v2;
}

vector<vector<int>> llenarMatriz(int size){
    vector<int> v1;
    vector<vector<int>> v2;
    int data;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            cin>>data;
            v1.push_back(data);
        }
        v2.push_back(v1);
        v1.erase(v1.begin(), v1.begin()+size);
    }

    return v2;
}

void imprimirMatriz(vector<vector<int>> mat, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<mat[i][j]<<" ";           
        }
        cout<<endl;
    }
}

int multiplicar(vector<vector<int>> v1, vector<vector<int>> v2, int size, int fila, int columna){
    int contador = 0;
    for(int i=0; i<size; i++){
        contador += v1[fila][i]*v2[i][columna];
    }

    return contador;
}

vector<vector<int>> multiplicacionMatrices(vector<vector<int>> v1, vector<vector<int>> v2, int size){
    vector<int> aux;
    vector<vector<int>> v3;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            aux.push_back(multiplicar(v1, v2, size, i, j));
        }
        v3.push_back(aux);
        aux.erase(aux.begin(), aux.begin()+size);
    }
    return v3;

}

int main(){

    int size;
    cout<<"Digite el el tamagno de las matrices: ";
    cin>> size;

    vector<vector<int>> v1 = llenarMatrizAleatorios(size);   
    vector<vector<int>> v2 = llenarMatrizAleatorios(size);

    double time_spend = 0.0;
    clock_t begin = clock();
    
    v3 = multiplicacionMatrices(v1, v2, size);
    
     clock_t end = clock();
    time_spend += (double)(end-begin)/CLOCKS_PER_SEC;
    //el tiempo está en milisegundos entonces divido ente 1000 para que sean segundos
    cout<<endl<<"Tiempo en hacer la multiplicacion sin hilos: "<<time_spend<<" s"<<endl;
  

    return 0;
}