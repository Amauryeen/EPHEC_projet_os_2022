#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
    int id;
    double s1;
    double s2;
    double s3;
    double tottour;
} voiture;

voiture v[20] = {{44}, {63}, {1}, {11}, {55}, {16}, {4}, {3}, {14}, {31}, {10}, {22}, {5}, {18}, {6}, {23}, {77}, {24}, {47}, {9}};

double generateTime(int lower, int upper){
    srand(clock());
    return (rand() % (upper - lower + 1)) + lower;
}

char formatTime(double time) {
    char buffer[8];
    int minutes = time / 60;
    int seconds = time / 1;
    int milliseconds = time / 0.001;
    
    sprintf(buffer, "%i:%i.%i", minutes, seconds, milliseconds);

    return *buffer;
}

int main() {
    double best1, best2, best3 = 99999;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            v[j].tottour = 99999;
            v[j].s1 = generateTime(25000, 45000) / 1000;
            best1 = v[j].s1;
            v[j].s2 = generateTime(25000, 45000) / 1000;
            best2 = v[j].s2;
            v[j].s3 = generateTime(25000, 45000) / 1000;
            best3 = v[j].s3;
            if (v[j].s1 + v[j].s2 + v[j].s3 < v[j].tottour){ v[j].tottour = v[j].s1 + v[j].s2 + v[j].s3; };        
        }
    }
    

    printf("==================================================================\nID\tBEST S1\t\tBEST S2\t\tBEST S3\t\tBEST TOTAL\n\n");
    for(int k = 0; k < 20; k++) {
        printf("%d\t%f\t%f\t%f\t%f\n", v[k].id, v[k].s1, v[k].s2, v[k].s3, v[k].tottour);
    }
    printf("==================================================================\n");

    char form = formatTime(568.15);
    printf("%i", form);
}
