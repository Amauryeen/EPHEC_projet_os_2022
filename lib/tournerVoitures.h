#define MIN_TIME 25000
#define MAX_TIME 45000

void turn() {
    for (int j = 0; j < 20; j++) { // Voitures
        v[j].tt = 99999;
        v[j].s1 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        v[j].s2 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        v[j].s3 = generateTime(MIN_TIME, MAX_TIME) / 1000;
        if (v[j].s1 + v[j].s2 + v[j].s3 < v[j].tt) {
            v[j].tt = v[j].s1 + v[j].s2 + v[j].s3;
        };
    }
}
