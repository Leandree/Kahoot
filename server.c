#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "utils.c"
#include <sys/wait.h>
#include <pthread.h>

int main(){
    // strcpy(&fichiersExistants[nbrFichiersExistants++],"s");
    // printf("%i\n",checkInTable(fichiersExistants,"..s"));

    int pid, j;
    pthread_t th;
    void * ret;
    pid = pthread_create(&th,NULL,listFichiers,0);
    pthread_join(th,&ret);

    // listFichiers();

    // for(int i=0; i<nbrFichiersExistants;i++){
    //     printf("%s\n",&fichiersExistants[i]);
    // }
    
}