#include <stdio.h>

int main() {
    int n, suma;
    char optiune;

    do {
        suma = 0; // Resetăm suma la fiecare calcul
        printf("Introduceti un numar: ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            suma += i; // Adunam fiecare numar la suma
        }

        printf("Suma numerelor de la 1 la %d este: %d\n", n, suma);

        // Întrebăm utilizatorul dacă dorește să continue
        printf("Doriti sa efectuati un alt calcul? (d/n): ");
        scanf(" %c", &optiune); // Adăugăm un spațiu înainte de `%c` pentru a consuma newline-ul lăsat de `scanf`.

    }

    while (optiune == 'd' || optiune == 'D'); // Continuăm dacă utilizatorul alege 'd' sau 'D'

    printf("Programul s-a incheiat. La revedere!\n");
    return 0;
}
