#include <stdio.h>

int main() {
    int a;
    float b;
    char c;

    // Citire variabile
    printf("Introduceti un numar intreg: ");
    scanf("%d", &a);

    printf("Introduceti un numar real: ");
    scanf("%f", &b);

    printf("Introduceti un caracter: ");
    scanf(" %c", &c);  // Observa spatiul inainte de %c pentru a evita eroarea cu newline

    // Afisare valori
    printf("Numarul intreg introdus este: %d\n", a);
    printf("Numarul real introdus este: %.2f\n", b);
    printf("Caracterul introdus este: %c\n", c);

    return 0;
}
