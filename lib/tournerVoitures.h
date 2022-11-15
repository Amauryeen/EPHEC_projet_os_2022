#define MIN_TIME 25000
#define MAX_TIME 45000

void turn() {
    for (int j = 0; j < 20; j++) { // Voitures
        voitures[j].tt = 99999;
        voitures[j].s1 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        voitures[j].s2 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        voitures[j].s3 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        if (voitures[j].s1 + voitures[j].s2 + voitures[j].s3 < voitures[j].tt) {
            voitures[j].tt = voitures[j].s1 + voitures[j].s2 + voitures[j].s3;
        };
    }
}
