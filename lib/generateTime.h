double generateTime(int lower, int upper){
    // Génère un temps aléatoire entre 'lower' et 'upper'
    srand(clock());
    return (rand() % (upper - lower + 1)) + lower;
}
