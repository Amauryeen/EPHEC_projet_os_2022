#ifndef __CAR__

#define __CAR__
#define INFINI 32000
#define NUMBER_KILOMETERS 300


typedef struct{
	int id;
	double s1;
	double s2;
    	double s3;
	double best1;
	double best2;
	double best3;
    	double tt;
	int isOut; //if isOut==1 -> car is out.
	int toStand; //if toStand==1 -> car is in the stand.
//	int distanceParcourue; // c'est des mètres
	double tempsTotal;
	int nbTours;
} Voiture;
int tabPilotes[] = {44, 63, 1, 11, 55, 16, 4, 3, 14, 31, 10, 22, 5, 18, 6, 23, 77, 24, 47, 9,-1};
int nbVoiture=sizeof(tabPilotes)/sizeof(tabPilotes[0])-1;
//void turnCar(Voiture* voitures,int raceId,sem_t *semaphore) {

void turnCar(Voiture* voitures,int raceId,int num) {
	//printf("ici\n");
	voitures[num].s1 = generateTime()/100 ;
	if(voitures[num].s1 < voitures[nbVoiture].s1){
		voitures[nbVoiture].s1=voitures[num].s1;
	}
	if(voitures[num].s1 < voitures[num].best1){voitures[num].best1 = voitures[num].s1;}
	//usleep(100000);
    	voitures[num].s2 = generateTime()/100;
	if(voitures[num].s2 < voitures[nbVoiture].s2){
		voitures[nbVoiture].s2 = voitures[num].s2;
	}
	if(voitures[num].s2 < voitures[num].best2){voitures[num].best2 = voitures[num].s2;}
	//usleep(100000);
	
    	voitures[num].s3 = generateTime() /100;
	if(voitures[num].s3 < voitures[nbVoiture].s3){
		voitures[nbVoiture].s3 = voitures[num].s3;
	}
	if(voitures[num].s3 < voitures[num].best3){voitures[num].best3 = voitures[num].s3;}
	//usleep(100000);
	//if(nbOut>0){
		//index=indexCarsOut(nbVoiture);
	//}
    	if (voitures[num].s1 + voitures[num].s2 + voitures[num].s3 < voitures[num].tt) {
            voitures[num].tt = voitures[num].s1 + voitures[num].s2 + voitures[num].s3;
    	}
	voitures[num].tempsTotal += voitures[num].s1 + voitures[num].s2 + voitures[num].s3;
	voitures[num].nbTours++;
	if(voitures[num].nbTours > voitures[nbVoiture].nbTours){
		voitures[nbVoiture].nbTours=voitures[num].nbTours;
	}
}
int seanceFinie(Voiture* voitures,int nbToursAFaire){
	return voitures[nbVoiture].nbTours == nbToursAFaire;
}
int calculNbTours(int longueurCircuit){
    int nbTours = NUMBER_KILOMETERS / longueurCircuit;
    if (nbTours * longueurCircuit < NUMBER_KILOMETERS) nbTours++;
    return  nbTours ;
}

void init(Voiture* voitures){
	for (int i = 0; i < nbVoiture+1; i++){
		voitures[i].id=tabPilotes[i];
		voitures[i].s1 = INFINI;
		voitures[i].s2 = INFINI;
		voitures[i].s3 = INFINI;
		voitures[i].tt = INFINI;
		voitures[i].isOut = 0;
		voitures[i].tempsTotal=0;
		voitures[i].nbTours=0;
		voitures[i].best1=INFINI;
		voitures[i].best2=INFINI;
		voitures[i].best3=INFINI;
	}
}
#endif // __CAR__

