#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include "car.h"

int compareTimes(const void *pa,const void *pb){
    const Voiture *p1 = (Voiture *)pa;
    const Voiture *p2 = (Voiture *)pb;
    return (int)((p1->tt - p2->tt)*1000000);
}
char s1[] = "-------";  // c’est ce qui sera affiché sur le last secteur 1 vaut INFINITE

char s2[] = "-------";

char s3[] = "-------"; // s1, s2 et s3 pour afficher le dernier temps du secteur S1, S2 ou S3

//if (voiture.s1 != INFINITE) { // si la valeur n’est pas infinie

//	snprintf(s1,8,"%7.4f",voiture.s1); // alors snprintf transforme le best s1 en string (avec 7 caractères à l’écran dont 4 chiffres derrière la virgule).
//}

//if (voiture.s2 != INFINITE) {

//	snprintf(s2,8,"%7.4f",voiture.s2);

//}

//if (voiture.s3 != INFINITE){

//	snprintf(s3,8,"%7.4f",voiture.s3);

//}
//void display(Voiture* voitures,  sem_t *semaphore){
void display(Voiture* voitures,sem_t *semaphore){
	char s1[] = "-------";
    	char s2[] = "-------";
    	char s3[] = "-------"; // pour afficher le dernier temps du secteur S1, S2 ou S3
	char tempsTotalAffiche[] = "-------";

	//printf("=======================================\nID\tS1\tS2\tS3\tTT\tDIFFn\n");
	//for(int k = 0; k < 20; k++) {
        	//printf("%d\t%7s\t%7s\t7s\t%.3f\n", voitures[k].id, s1, s2, s3, voitures[k].tt);
    	//}
    	//printf("=======================================\n");

	//printf("Après le tri...\n");
	Voiture * copie = (Voiture *) malloc ((nbVoiture+1) * sizeof(Voiture));
	
	sem_wait(semaphore);
	memcpy (copie, voitures, (nbVoiture+1) * sizeof(Voiture));
	sem_post(semaphore);
	
	qsort(copie,nbVoiture,sizeof(Voiture),compareTimes);
	
	

	printf("=======================================\nID\tS1\tS2\tS3\tTT\tDIFF\tnbTours\n\n");
	//printf("| %*s | %*s | %*s | %*s | %*s | %*s | %*s |\n",5,"ID",10,"S1",10,"S2",10,"S3",10,"TT",10,"DIFF",6,"nbTours");
        //printf("|____________|____________|____________|____________|____________|____________|____________|\n");
	//printf("┌─────┬─────┬─────────┬─────────┬─────────┬───────┬─────────┬─────┐\n");
	if (copie[0].s1 != INFINI){
        		snprintf(s1,8,"%7.4f",copie[0].s1);
    	}
    	if (copie[0].s2 != INFINI){
        		snprintf(s2,8,"%7.4f",copie[0].s2);
    	}
    	if (copie[0].s3 != INFINI){
        		snprintf(s3,8,"%7.4f",copie[0].s3);
    	}
    	if (copie[0].tt != INFINI){
        	snprintf(tempsTotalAffiche,8,"%7.4f",copie[0].tt);
    	}
	
    	printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\n", copie[0].id, s1, s2, s3, tempsTotalAffiche, 000, copie[0].nbTours);
	for(int k = 1; k < nbVoiture; k++) {
		if (copie[k].s1 != INFINI){
        		snprintf(s1,8,"%7.4f",copie[k].s1);
    		}
    		if (copie[k].s2 != INFINI){
        		snprintf(s2,8,"%7.4f",copie[k].s2);
    		}
    		if (copie[k].s3 != INFINI){
        		snprintf(s3,8,"%7.4f",copie[k].s3);
    		}
    		if (copie[k].tt != INFINI){
        		snprintf(tempsTotalAffiche,8,"%7.4f",copie[k].tt);
    		}

        	printf("%d\t%s\t%s\t%s\t%s\t%.3f\t%d\n", copie[k].id, s1, s2, s3, tempsTotalAffiche, copie[k].tt - copie[k-1].tt, copie[k].nbTours);
    	}
    	printf("=======================================\n");
	printf("Le best S1 est %.3f\n",copie[nbVoiture].s1);
	printf("Le best S2 est %.3f\n",copie[nbVoiture].s2);
	printf("Le best S3 est %.3f\n",copie[nbVoiture].s3);
	//printf("┌─────┬───────────────┬─────────┬─────────┬───────┬─────────┬─────┐\n");

        //printf("│ ID  │   S1    │ S2      │    S3   │    TT   │ DIFF  │         │     │\n");

        //printf("├─────┼─────┼─────────┼─────────┼─────────┼───────┼─────────┼─────┤\n");
	//printf("┬─────┬─────────┬─────────┬─────────┬───────┬─────────┬─────┐\n");

    	//printf("│ ID  │    S1   │    S2   │    S3   │ TT    │ DIFF    │ out │\n");

    	//printf("┼─────┼─────────┼─────────┼─────────┼───────┼─────────┼─────┤\n");


	//for(int k = 0; k < 20; k++) {
        //printf("│  %d │   %.3f  │    %.3f │    %.3f │  %.3f │  ----   │  ---│\n",

                //copie[k].id, copie[k].s1, copie[k].s2, copie[k].s3, copie[k].tt

                //);
	//}
	//printf("┴─────┴─────────┴─────────┴─────────┴───────┴─────────┴─────┘\n");
        //printf("└─────┴─────┴─────────┴─────────┴─────────┴───────┴─────────┴─────┘\n");
}


