#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *procesoSeparado(void *data){
    char *texto = (char *) data;
   // struct timespec tiempo = {1, 0};
    while(1){
        printf("%s\n", texto);
        //pthread_delay_np(&tiempo);
        sleep(1);
    }

}

int main(){

    pthread_t proceso1;
    pthread_t proceso2;

    pthread_create(&proceso1, NULL, &procesoSeparado, "Hola");
    pthread_create(&proceso2, NULL, &procesoSeparado, "adiós");

    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);
    pthread_exit(NULL);
}