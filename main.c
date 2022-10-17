#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int id;
    double s1;
    double s2;
    double s3;
    double tottour;
} voiture;

double generer_temps(int lower, int upper){
    srand(clock());
    return (rand() % (upper - lower + 1)) + lower;
}
int main() {
    voiture v[20] = {{44}, {63}, {1}, {11}, {55}, {16}, {4}, {3}, {14}, {31}, {10}, {22}, {5}, {18}, {6}, {23}, {77}, {24}, {47}, {9}};
    double best1, best2, best3 = 99999;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            v[j].tottour = 99999;
            v[j].s1 = generer_temps(25000, 45000) / 1000;
            best1 = v[j].s1;
            v[j].s2 = generer_temps(25000, 45000) / 1000;
            best2 = v[j].s2;
            v[j].s3 = generer_temps(25000, 45000) / 1000;
            best3 = v[j].s3;
            if (v[j].s1 + v[j].s2 + v[j].s3 < v[j].tottour){ v[j].tottour = v[j].s1 + v[j].s2 + v[j].s3; };        
        }
    }
    

    printf("==================================================================\nID\tS1\t\tS2\t\tS3\t\tTOT\n\n");
    for(int k = 0; k < 20; k++) {
        printf("%d\t%f\t%f\t%f\t%f\n", v[k].id, v[k].s1, v[k].s2, v[k].s3, v[k].tottour);
    }
    printf("==================================================================\n");
}
