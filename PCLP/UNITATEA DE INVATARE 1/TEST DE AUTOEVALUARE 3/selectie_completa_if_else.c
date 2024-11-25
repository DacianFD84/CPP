#include <stdio.h>

int main() {
    int numar;
    printf("Introduceti un numar: ");
    scanf("%d", &numar);

    if (numar > 0) {
        printf("Numarul este pozitiv.\n");
    } else {
        printf("Numarul este negativ sau zero.\n");
    }

    return 0;
}
