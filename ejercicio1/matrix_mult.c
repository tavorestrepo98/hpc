#include <stdio.h>
#include <stdlib.h>

int multiplicar(int a[][3], int b[][3], int fila, int columna, int size){
    int contador = 0;
    for(int i=0; i<size; i++){
        contador += a[fila][i]*b[i][columna];
    }

    return contador;
}


void multiplicacionMatrices(int size, int vec1[][3], int vec2[][3], int vec3[][3]){
    for(int i=0; i<size; i++){
        for(int j=0; i<size; i++){
            vec3[i][j]= multiplicar(vec1, vec2, i, j, size);
        }
    }

}

void llenarMatriz(int a[3][3], int size){
    for(int i=0; i<size; i++){
        for(int j=0; i<size; j++){
            scanf("%d", &a[i][j]);
            printf("%d", a[i][j]);
        }
    }

}   

void imprimirMatriz(int a[][3], int size){
    for(int i=0; i<size; i++){
        for(int j=0; i<size; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n=3;
    int a[n][n];
    int b[n][n];

    //Llenar matrices

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            printf("%d", a[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; i<n; j++){
            scanf("%d", &a[i][j]);
            printf("%d", a[i][j]);
        }
    }
    
    llenarMatriz(a, n);
    imprimirMatriz(a, n);






    return 0;
}