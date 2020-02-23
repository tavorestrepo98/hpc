#include <stdio.h>
#include <stdlib.h>

struct Persona{
    char nombre[30];
    int edad;
}persona, *puntero_persona = &persona;

void pedirDatos(){
    printf("Digite el nombre: ");
    scanf("%s", puntero_persona->nombre);
    printf("Digite la edad: ");
    scanf("%i", &puntero_persona->edad);
}

void imprimir(struct Persona *persona){
    printf("Mi nombre es: %s\n", persona->nombre);  
    printf("Mi edad es: %i\n", persona->edad);
}

int main(){
    pedirDatos();
    imprimir(puntero_persona);

    return 0;
}