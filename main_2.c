#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MIN_TIME  25000
#define MAX_TIME  45000

typedef struct{
    int id;
    double s1;
    double s2;
    double s3;
    double tt;
} Voiture;

Voiture v[20] = {{44}, {63}, {1}, {11}, {55}, {16}, {4}, {3}, {14}, {31}, {10}, {22}, {5}, {18}, {6}, {23}, {77}, {24}, {47}, {9}};

double generateTime(int lower, int upper){
    // Génère un temps aléatoire entre 'lower' et 'upper'
    srand(clock());
    return (rand() % (upper - lower + 1)) + lower;
}

void bestTime(char type[2]){
    print('%s', v[0][type]);
}

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

void turn() {
    for (int j = 0; j < 20; j++) { // Voitures
        v[j].tt = 99999;
        v[j].s1 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        v[j].s2 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        v[j].s3 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        if (v[j].s1 + v[j].s2 + v[j].s3 < v[j].tt) {
            v[j].tt = v[j].s1 + v[j].s2 + v[j].s3;
        };
    }
}

int main() {
//    for (int i = 0; i < 10; i++) { // Tours
        turn();
//    }
    bestTime('s1');
    

    printf("=======================================\nID\tS1\tS2\tS3\tTT\n\n");
    for(int k = 0; k < 20; k++) {
        printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\n", v[k].id, v[k].s1, v[k].s2, v[k].s3, v[k].tt);
    }
    printf("=======================================\n");
}
//    mémoire partagée
int shmid=shmget(1000,20*sizeof(voiture),0666 | IPC_CREATE);
if (shmid == -1) {
        printf("shmget() failed !");
}
struct voiture *circuit;
circuit=shmat(shmid,0,0);
if (circuit == -1) {
        printf("shmat() failed !");
}
//circuit = (struct voiture *) shmat(shmid,0,0);
int pid;
for (i=0;i<20;i++){
    pid=fork();

    if (pid == -1){ //tester s'il y a une erreur dans le fork
        printf("Error in fork()");
    }
    if (pid ==0){//exécution du fils

    }
    if (pid > 0){ // exécution du père

    }


}
