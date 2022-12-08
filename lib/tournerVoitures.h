#define MIN_TIME 25000
#define MAX_TIME 45000

void turn() {
    for (int i = 0; i < 20; i++) { // Voitures
        voitures[i].tt = 99999;
        voitures[i].s1 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        voitures[i].s2 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        voitures[i].s3 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        if (voitures[i].s1 + voitures[i].s2 + voitures[i].s3 < voitures[i].tt) {
            voitures[i].tt = voitures[i].s1 + voitures[i].s2 + voitures[i].s3;
        };
    }
}
