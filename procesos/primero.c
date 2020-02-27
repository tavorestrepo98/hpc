#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int var = 22;

int main(){
    pid_t id;
     
    printf("** Proc. PID = %d comienza **\n", getpid());

    id = fork();

    printf("** Proc. PID = %d, id = %d  ejecutandoce **\n", getpid(), id);

    if(id > 0){
        var = 44;
    }else if (id == 0){
        var = 33;
    }

    while (1){
        sleep(2);
        printf("** Proc. PID = %d, id = %d, var = %d ejecutandoce **\n", getpid(), id, var);
    }
    
    
    
       

    return 0;
}