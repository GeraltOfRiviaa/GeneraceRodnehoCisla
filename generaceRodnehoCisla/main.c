#include <stdio.h>
#include <stdlib.h>


int otazka(char *otazka) {
    int odpoved;
    printf("Zadej %s: ", otazka);
    scanf("%d", &odpoved);
    return odpoved;
}
int generaceCisla(int rok, int mesic, int den, int pohlavi, int posTroj) {
    char id[5] = {00,00,00,000,0};
    if (rok < 2000) {
        id [0] = (rok - 1900) + '\0';
    }
    else {
        id [0] = rok - 2000 + '\0';
    }
    if (pohlavi == 1) {
        id[1] = mesic + 50 + '\0';
    }
    else if (mesic <=9) {
        id[1] = '0' + den + '\0';
    }
    else {
        id[1] = mesic + '\0';
    }
    if (den <= 9 ) {
        id[2] = '0' + den + '\0';
    }
    else {
        id[2] = den + '\0';
    }
    sprintf(id, "%02d%02d%02d/%03d", rok, mesic, den, posTroj);

    return atoi(id);
}

int main(void) {
    int rok = otazka("rok");
    int mesic = otazka("mesic");
    int den= otazka("den");
    int pohlavi = otazka("pohlavi (1 = zena, 0 = muz)");
    int specialniIdentifikator = otazka("posledni trojcisli");
    printf("%d",generaceCisla(rok, mesic, den, pohlavi, specialniIdentifikator));



    return 0;
}
