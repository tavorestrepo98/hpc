#include <iostream>
#include <vector>
#include <pthread.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>


using namespace std;

vector<vector<int>> v1;   
vector<vector<int>> v2;
vector<vector<int>> v3;

vector<vector<int>> llenarMatrizAleatorios(int size){
    vector<int> aux;
    vector<vector<int>> vector;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            aux.push_back((int)(rand() % 20));
        }
        vector.push_back(aux);
        aux.erase(aux.begin(), aux.begin()+size);
    }

    return vector;
}

vector<vector<int>> llenarMatrizCeros(int size){
    vector<int> aux;
    vector<vector<int>> vector;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            aux.push_back(0);
        }
        vector.push_back(aux);
        aux.erase(aux.begin(), aux.begin()+size);
    }

    return vector;
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
    vector<vector<int>> matrix;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            aux.push_back(multiplicar(v1, v2, size, i, j));
        }
        matrix.push_back(aux);
        aux.erase(aux.begin(), aux.begin()+size);
    }
    return matrix;

}

void *Procesomultiplicar(void *data){
   int *informacion = (int *) data;

   int size = informacion[0];
      
   vector<int> aux;
   
   for(int i=0; i<informacion[1]; i++){
       for(int j=0; j<size; j++){
           aux.push_back(multiplicar(v1, v2, size, i, j));
       }
       v3[i] = aux;
       aux.erase(aux.begin(), aux.begin()+size);
    }

}

//Rutina 2 para el proceso de multiplicar las matrices
void *Procesomultiplicar2(void *data){
   int *informacion = (int *) data;

   int size = informacion[0];
   vector<int> aux;
   
   for(int i=informacion[2]; i<size; i++){
       for(int j=0; j<size; j++){
           aux.push_back(multiplicar(v1, v2, size, i, j));
       }
       v3[i] = aux;
       aux.erase(aux.begin(), aux.begin()+size);
    }
}

int main(){
    
    //Creo los procesos que voy a utilizar
    pthread_t proceso1;
    pthread_t proceso2;
    
    int size;
    cout<<"Digite el el tamagno de las matrices: ";
    cin>> size;

    //lleno las matrices que van a ser multiplicadas
    //y la matriz resultado con ceros
    v1 = llenarMatrizAleatorios(size);   
    v2 = llenarMatrizAleatorios(size);
    v3 = llenarMatrizCeros(size);
    
    int mitad = size/2;
    int informacion[3] = {size, mitad, mitad};

    //divido la operacion de multiplicar en dos hilos
    //lo cual significa que en un hilo ejecuto la mitad de la matriz
    //y en el otro hilo la otra mitad
    //si el tamaño de las matrices no es par entonces un hilo resuelve una fila de más
    if(size%2 != 0){
        informacion[2] =  mitad+1;       
    }

    int conteo = 0;

    //inicializo las variables para tomar los tiempos
    double time_spend = 0.0;
    

    while (conteo < 10)
    {
        time_spend = 0.0;
        clock_t begin = clock();
        //Creo los hilos y los ejecuto con sus rutinas
        pthread_create(&proceso1, NULL, &Procesomultiplicar, informacion);
        pthread_create(&proceso2, NULL, &Procesomultiplicar2, informacion);
        pthread_join(proceso1, NULL);
        pthread_join(proceso2, NULL);


        clock_t end = clock();
        time_spend += (double)(end-begin) / CLOCKS_PER_SEC;
        //el tiempo está en milisegundos entonces divido ente 1000 para que sean segundos
        cout<<endl<<"Tiempo en hacer la multiplicacion con hilos: "<<time_spend/2.0<<" s"<<endl;
        conteo += 1;
    }
      

    return 0;
}