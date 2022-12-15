#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "lib/car.h"
#include "lib/generateTime.h"
#include "lib/turnCar.h"
#include "lib/display.h"

int main() {
    //for (int i = 0; i < 10; i++) { // Tours
    //    turn();
    //}
    

   // printf("=======================================\nID\tS1\tS2\tS3\tTT\n\n");
   // for(int k = 0; k < 20; k++) {
      //  printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\n", voitures[k].id, voitures[k].s1, voitures[k].s2, voitures[k].s3, voitures[k].tt);
   // }
   // printf("=======================================\n");
    
    // mémoire partagée
    int shmid = shmget(1000, 21 * sizeof(Voiture), 0666 | IPC_CREAT);
    if (shmid == -1) {
            printf("shmget() failed !");
    }
    
    struct Voiture *circuit;
    //circuit = (void *) shmat(shmid,0,0);
    circuit = (struct Voiture *) shmat(shmid, 0, 0);
    if (circuit == NULL) {
            printf("shmat() failed !");
    }
    
    for (int i = 0; i < 20; i++) {

        if(fork() == -1) { // tester s'il y a une erreur dans le fork
            printf("Error in fork()");
        }

        else if(fork() == 0) { // Fils
            turnCar();
            exit(0);
        }
	else { display(); }
    }
	
}
