#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "lib/voitures.h"
#include "lib/genererTemps.h"
#include "lib/tournerVoitures.h"

//void bestTime(char type[2]){
//    printf('%s', v[0]);
//}

//char formatTime(char * test[], double time) {
//    char buffer[8];
//    int minutes = time / 60;
//    int seconds = time / 1;
//    int milliseconds = time / 0.001;
//
//    sprintf(*test, "%i:%i.%i", minutes, seconds, milliseconds);
//
//    return test;
//}

int main() {
    for (int i = 0; i < 10; i++) { // Tours
        turn();
    }
    

    printf("=======================================\nID\tS1\tS2\tS3\tTT\n\n");
    for(int k = 0; k < 20; k++) {
        printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\n", v[k].id, v[k].s1, v[k].s2, v[k].s3, v[k].tt);
    }
    printf("=======================================\n");
    
    // mémoire partagée
    int shmid = shmget(1000, 20 * sizeof(Voiture), 0666 | IPC_CREAT);
    if (shmid == -1) {
            printf("shmget() failed !");
    }
    
    struct Voiture *circuit;
    circuit = (void *) shmat(shmid,0,0);
    //circuit = (struct voiture *) shmat(shmid,0,0);
    if (circuit == -1) {
            printf("shmat() failed !");
    }
    
    int pid;
    for (int i = 0; i < 20; i++){
        pid = fork();

        if (pid == -1){ // tester s'il y a une erreur dans le fork
            printf("Error in fork()");
        }
        if (pid ==0){ // exécution du fils

        }
        if (pid > 0){ // exécution du père

        }


    }
}
