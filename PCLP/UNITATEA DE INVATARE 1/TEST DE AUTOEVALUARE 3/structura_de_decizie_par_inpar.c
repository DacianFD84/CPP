#include <stdio.h>

int main() {
    int numar;

    printf("Introduceti un numar: ");
    scanf("%d", &numar);

    // Verificăm dacă numărul este par sau impar
    if (numar % 2 == 0) {
        printf("Numarul %d este par.\n", numar);
    }

    else {
        printf("Numarul %d este impar.\n", numar);
    }

    return 0;
}

/* Dacă utilizatorul introduce 4, atunci:

4 % 2 = 0 → Condiția numar % 2 == 0 este adevărată.
Se execută blocul if și afișează: Numarul 4 este par.
Dacă utilizatorul introduce 5, atunci:

5 % 2 = 1 → Condiția numar % 2 == 0 este falsă.
Se execută blocul else și afișează: Numarul 5 este impar. */
