#include <stdio.h>

int main() {
    int optiune;

    printf("Alege o optiune (1, 2 sau 3): ");
    scanf("%d", &optiune);

    // Structură de selecție
    switch (optiune) {
        case 1:
            printf("Ati ales optiunea 1.\n");
            break;
        case 2:
            printf("Ati ales optiunea 2.\n");
            break;
        case 3:
            printf("Ati ales optiunea 3.\n");
            break;
        default:
            printf("Optiune invalida.\n");
    }

    return 0;
}
