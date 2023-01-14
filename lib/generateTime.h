
#define TEMPS_P1 3600       //TEMPS POUR P1 (1H) 20tours
#define TEMPS_P2 3600       //TEMPS POUR P2 (1H) 20
#define TEMPS_P3 3600       //TEMPS POUR P3 (1H) 20 tours
#define TEMPS_Q1 1080       //TEMPS POUR Q1 (18 Minutes) 10
#define TEMPS_Q2 900        //TEMPS POUR Q2 (15 Minutes) 7
#define TEMPS_Q3 720        //TEMPS POUR Q3 (12 Minutes) 3
#define MIN_CARS_OUT 0
#define MAX_CARS_OUT 3
#define MAXTIMETURN 40000 //TEMPS MAX D'UN TOUR
#define MINTIMETURN 25000 //TEMPS MIN D'UN TOUR
#define MINSTANDTIME 5000   //TEMPS MINIMUM D'UN ARRET AU STAND
#define MAXSTANDTIME 10000  //TEMPS MAXIMUM D'UN ARRET AU STAND



double generateTime(){
    // Génère un temps aléatoire entre 'lower' et 'upper'
	int lower;
	int upper;	
	srand(clock());


	upper= MAXTIMETURN;
	
	lower=MINTIMETURN;
	
	return (rand() % (upper - lower + 1)) + lower;
}
//int numberOfCarsOut(int min, int max){
//	//Génère un temps aléatoire entre 'min' et 'max'
//	srand(clock());
//	return (rand() % (upper - lower + 1)) + lower;
//}

//int indexCarsOut(int numberOfCars){
//	srand(clock());
//	return (rand() % (numberOfCars + 1);
//}
//double generateTime(int lower, int upper){
    // Génère un temps aléatoire entre 'lower' et 'upper'
//    srand(clock());
//    return (rand() % (upper - lower + 1)) + lower;
//}


