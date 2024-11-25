#include <stdio.h>

int main() {
    int zi;
    printf("Introduceti un numar de la 1 la 7 pentru ziua saptamanii: ");
    scanf("%d", &zi);

    switch (zi) {
        case 1:
            printf("Luni\n");
            break;
        case 2:
            printf("Marti\n");
            break;
        case 3:
            printf("Miercuri\n");
            break;
        case 4:
            printf("Joi\n");
            break;
        case 5:
            printf("Vineri\n");
            break;
        case 6:
            printf("Sambata\n");
            break;
        case 7:
            printf("Duminica\n");
            break;
        default:
            printf("Numar invalid.\n");
    }

    return 0;
}
