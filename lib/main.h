for (int i = 0; i < 10; i++) { // Tours
    turn();
}
    

printf("=======================================\nID\tS1\tS2\tS3\tTT\n\n");
for(int k = 0; k < 20; k++) {
    printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\n", v[k].id, v[k].s1, v[k].s2, v[k].s3, v[k].tt);
}
printf("=======================================\n");
