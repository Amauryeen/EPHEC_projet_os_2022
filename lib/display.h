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


void display(Voiture* voitures,sem_t *semaphore){
	char s1[] = "-------";
    	char s2[] = "-------";
    	char s3[] = "-------"; // pour afficher le dernier temps du secteur S1, S2 ou S3
	char tempsTotalAffiche[] = "-------";

	Voiture * copie = (Voiture *) malloc ((nbVoiture+1) * sizeof(Voiture));
	
	sem_wait(semaphore);
	memcpy (copie, voitures, (nbVoiture+1) * sizeof(Voiture));
	sem_post(semaphore);
	
	qsort(copie,nbVoiture,sizeof(Voiture),compareTimes);
	
	printf("┌─────┬────────┬─────────┬─────────┬─────────┬────────┬─────────┐\n");
	printf("│ ID  │   S1   │    S2   │    S3   │    TT   │  DIFF  │ nbTours │\n");
	printf("├─────┼────────┼─────────┼─────────┼─────────┼────────┼─────────┤\n");
	if (copie[0].s1 != INFINI){
        		snprintf(s1,8,"%7.3f",copie[0].s1);
    	}
    	if (copie[0].s2 != INFINI){
        		snprintf(s2,8,"%7.3f",copie[0].s2);
    	}
    	if (copie[0].s3 != INFINI){
        		snprintf(s3,8,"%7.3f",copie[0].s3);
    	}
    	if (copie[0].tt != INFINI){
        	snprintf(tempsTotalAffiche,8,"%7.3f",copie[0].tt);
    	}
	
	printf("│  %2d │%-7s │ %-7s │ %-7s │ %-7s │  000   │   %-6d│\n",copie[0].id, s1, s2, s3,tempsTotalAffiche, copie[0].nbTours);
	for(int k = 1; k < nbVoiture; k++) {
		if (copie[k].s1 != INFINI){
        		snprintf(s1,8,"%7.3f",copie[k].s1);
    		}
    		if (copie[k].s2 != INFINI){
        		snprintf(s2,8,"%7.3f",copie[k].s2);
    		}
    		if (copie[k].s3 != INFINI){
        		snprintf(s3,8,"%7.3f",copie[k].s3);
    		}
    		if (copie[k].tt != INFINI){
        		snprintf(tempsTotalAffiche,8,"%7.3f",copie[k].tt);
    		}
		printf("│  %2d │%-7s │ %-7s │ %-7s │ %-7s │%7.3f │   %-6d│\n",copie[k].id, s1, s2, s3, tempsTotalAffiche,copie[k].tt - copie[k-1].tt, copie[k].nbTours);

    	}
	printf("└─────┴────────┴─────────┴─────────┴─────────┴────────┴─────────┘\n");
	printf("%s","");
	printf("┌─────────┬─────────┬─────────┐\n");
	printf("│ BestS1  │ BestS2  │ BestS3  │\n");
	printf("├─────────┼─────────┼─────────┤\n");
	printf("│ %7.3f │ %7.3f │ %7.3f │\n",copie[nbVoiture].s1, copie[nbVoiture].s2,copie[nbVoiture].s3);
	printf("└─────────┴─────────┴─────────┘\n");
    	
}


