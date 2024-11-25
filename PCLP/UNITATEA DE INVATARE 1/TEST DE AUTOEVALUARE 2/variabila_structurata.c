#include <stdio.h>

// Definirea structurii pentru 3 numere
struct MediaAritmetica3Numere {
    int numar1;
    int numar2;
    int numar3;
};

int main() {
    struct MediaAritmetica3Numere numere;  // variabilă structurată

    // Citirea valorilor de la utilizator
    printf("Introduceti primul numar: ");
    scanf("%d", &numere.numar1);

    printf("Introduceti al doilea numar: ");
    scanf("%d", &numere.numar2);

    printf("Introduceti al treilea numar: ");
    scanf("%d", &numere.numar3);

    // Calcularea mediei aritmetice
    float media = (numere.numar1 + numere.numar2 + numere.numar3) / 3.0;

    // Afisarea mediei aritmetice
    printf("Media aritmetica a celor 3 numere este: %.0f\n", media);

    system("pause");

    return 0;
}
