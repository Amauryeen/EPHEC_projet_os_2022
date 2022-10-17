#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int id;
    double s1;
    double s2;
    double s3;
    double tottour;
}voiture;

void generer_temps(lower,upper){
    double upper;
    double lower;
    double temps;
    srand(time(NULL));
    temps=(rand() % (upper-lower+1))+lower;
}
voiture v[20]={44, 63, 1, 11, 55, 16, 4, 3, 14, 31, 10, 22, 5, 18, 6, 23, 77, 24, 47, 9};
double best1=90000;
double best2=90000;
double best3=90000;
int i,j;
for (i=0;i<=5;i++){
    for (j=0;j<=10;j++){
        v[j].tottour=90000;
        v[j].s1=generer_temps(25,45);
        if (v[j].s1<best1){best1=v[j].s1};
        v[j].s2=generer_temps(25,45);
        if (v[j].s2<best2){ best2=v[j].s2};
        v[j].s3=generer_temps(25,45);
        if (v[j].s3<best3){ best2=v[j].s3};
        if (v[j].s1+v[j].s2+v[j].s3 < v[j].tottour){ v[j].tottour = v[j].s1+v[j].s2+v[j].s3 };        
    }
}
