#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int participants[20][4] = {{44}, {63}, {1}, {11}, {55}, {16}, {4}, {3}, {14}, {31}, {10}, {22}, {5}, {18}, {6}, {23}, {77}, {24}, {47}, {9}};
    int i;
    int tempsMax = 45000;
    int tempsMin = 25000;
    int meilleurTemps[3] = {0,0,0};

    for (i = 0; i < sizeof (participants) / sizeof (participants[0]); i++){
        int j, n;
        for (j = 0; j < 3; j++){
            n = rand()%(tempsMax - tempsMin) + tempsMin;
            participants[i][j+1] = n / 1000;
            if(participants[i][j+1] > meilleurTemps[j]){
                meilleurTemps[j+1] = participants[i][j+1];
            }else{}
        }



    }

    printf("%d\n",meilleurTemps[1]);
    printf("%d\n",meilleurTemps[2]);
    printf("%d\n",meilleurTemps[3]);

    return 0;
}
