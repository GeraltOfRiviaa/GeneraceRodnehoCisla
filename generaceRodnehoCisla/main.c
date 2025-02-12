#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Funkce pro kontrolu přestupného roku
bool prestupnyRok(int rok) {
    return (rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0);
}

// Funkce pro získání počtu dní v měsíci
int dnyVMesici(int mesic, int rok) {
    int dny[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mesic == 2 && prestupnyRok(rok)) {
        return 29;
    }
    return dny[mesic - 1];
}



// Funkce pro generování rodného čísla
void generateRodneCislo(int rok, int mesic, int den, char pohlavi, int unikatniCislo, char* rodneCislo[11]) {
    
    if (pohlavi == '1') {
        mesic += 50;
    }
    
    rok = rok % 100;
    
    // Sestavení prvních 9 číslic rodného čísla
    sprintf(rodneCislo, "%02d%02d%02d%03d", rok, mesic, den, unikatniCislo);
    
    // Výpočet kontrolní číslice
    long long cislo = atoll(rodneCislo);
    int posledniCislo;
    for(int i = 1; i < 10; i++) {
        /*
        if ((cislo * 10 + i) % 11 == 0) {
            posledniCislo = i;
            break;
        }
        */
        if (cislo % 11 == i){
            posledniCislo = i;
            break;
        }
        else if (cislo % 11 == 10){
            posledniCislo = 0;
            break;
        }
    }
    
    // Přidání kontrolní číslice
    sprintf(rodneCislo, "%02d%02d%02d%03d%d", rok, mesic, den, unikatniCislo, posledniCislo);
}
int otazka(const char *predmet, int intervalZ, int intervalK){
    int Predmet;
    int buffer = 0;
    do
    {
        printf("Zadej %s v intervalu %d - %d: ", predmet, intervalZ, intervalK);
    scanf("%d",&Predmet);
    while (getchar() != '\n')
    {
        buffer++;
    }
    
    if (Predmet < intervalZ || Predmet > intervalK){
        printf("Jsi mimo interval!!!");
    }
    else if (buffer > 0){
        printf("Zadal jsi pismeno!!!");
    }
    } while (buffer > 0 || Predmet < intervalZ || Predmet > intervalK);
    
    return Predmet;
}

int main() {
    int rok, mesic, den, unikatniCisla, pohlavi;
    char rodneCislo[11];
    
        rok = otazka("rok", 1954,2025);
        mesic = otazka("mesic", 1,12);
        den = otazka("den", 1,dnyVMesici(mesic, rok));
        pohlavi = otazka("pohlavi", 0,1);
        unikatniCisla = otazka("unikatni cislo", 0,999);
    
    // Generování rodného čísla
    generateRodneCislo(rok, mesic, den, pohlavi, unikatniCisla, rodneCislo);
    
    // Výpis výsledku
    printf("\nVygenerovane validni rodne cislo: %s\n", rodneCislo);
    
    return 0;
}
