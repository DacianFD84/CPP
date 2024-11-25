#include <stdio.h>
#include <math.h>

int main() {
    float AB, AC, BC, perimetru, raza;
    printf("Introduceti lungimea catetei AB: ");
    scanf("%f", &AB);
    printf("Introduceti lungimea catetei AC: ");
    scanf("%f", &AC);
    BC = sqrt(AB * AB + AC * AC);
    perimetru = AB + AC + BC;
    raza = BC / 2;
    printf("Perimetrul triunghiului dreptunghic este: %.2f\n", perimetru);
    printf("Raza cercului circumscris este: %.2f\n", raza);

    return 0;
}
