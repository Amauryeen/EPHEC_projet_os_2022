#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

#include "lib/generateTime.h"
#include "lib/car.h"
#include "lib/display.h"

int gettypeRace(char *argv[]);

sem_t *semaphore;
int raceTime;
Voiture *circuit;
int nbToursAFaire;



int main(int argc, char *argv[]){
	//semaphore
	int shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	semaphore = shmat (shmid,0,0);
	sem_init(semaphore,0,20);
	if (argc != 2){
        	printf("Veuillez passer 1 seul paramètre!\n");
        	exit(EXIT_FAILURE);
    	}
	int raceId = gettypeRace(argv);
	if (raceId == -1){
        	printf("Erreur, parametre invalide (P1, P2, P3, Q1, Q2, Q3, F)\n");
        	exit(EXIT_FAILURE);
	}

	else {
		
		switch(raceId){
			case 1 : case 2 : case 3 : nbToursAFaire=50;break;
			case 4 : nbToursAFaire=20;break;
			case 5 : nbToursAFaire=15;break;
			case 6 : nbToursAFaire=10;break;
			case 7 : nbToursAFaire=calculNbTours(4.675);

		}
		int shmid = shmget(1000, (nbVoiture+1) * sizeof(Voiture), 0666 | IPC_CREAT);
    		if (shmid == -1) {
            		printf("shmget() failed !");
    		}

    		circuit = ( Voiture *) shmat(shmid, 0, 0);
    		init(circuit);
    		if (circuit == NULL) {
            		printf("shmat() failed !");
            		exit(-2);
    		}
		display(circuit,semaphore);
    		for (int i = 0; i < 20; i++) {
                	int pid=fork();

        		if(pid == -1) { // tester s'il y a une erreur dans le fork
            			printf("Error in fork()");
            			exit(-1);
        		} else
        		if(pid == 0) { // Fils
                    		for(int j=0;j<nbToursAFaire;j++){
                        		sem_wait(semaphore);
                        		turnCar(circuit,raceId,i);
                        		sem_post(semaphore);
                        		usleep(300000);
                    		}

                    		exit(0); // le fils arrête car il a fait tous ses tours
        		}
            	}
	}
	int i=0;
	while(!seanceFinie(circuit,nbToursAFaire)){
			i++;
			printf("Affichage %d\n",i);
			
			display(circuit,semaphore);
			
			usleep(1000000);

	}
	i++;
	printf("Affichage %d\n",i);
	
	display(circuit,semaphore);
	
	usleep(1000000);

	sem_destroy(semaphore);
	printf("La séance %s est finie\n",argv[1]);

}

int gettypeRace(char *argv[]){
    	if(strcmp(argv[1], "P1" ) == 0){
        	nbVoiture = 20;
        	raceTime = TEMPS_P1;
        	return 1;

    	}
    	else if(strcmp(argv[1], "P2") == 0) {
        	nbVoiture = 20;
        	raceTime = TEMPS_P2;
        	return 2;

    	}
    	else if(strcmp(argv[1], "P3") == 0) {
        	nbVoiture = 20;
        	raceTime = TEMPS_P3;
        	return 3;

    	}
    	else if(strcmp(argv[1], "Q1") == 0) {
        	nbVoiture = 20;
        	raceTime = TEMPS_Q1;
        	return 4;

    	}
    	else if(strcmp(argv[1], "Q2") == 0) {
        	nbVoiture = 15;
        	raceTime = TEMPS_Q2;
        	return 5;

    	}
    	else if(strcmp(argv[1], "Q3")  == 0) {
        	nbVoiture = 10;
        	raceTime = TEMPS_Q3;
        	return 6;

    	}
    	else if(strcmp(argv[1], "F")  == 0) {
        	nbVoiture = 20;
        	return 7;

    	}
	else{
    		return -1;
	}
}
