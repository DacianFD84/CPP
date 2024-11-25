#include <stdio.h>

int main() {
    int nota;
    printf("Introduceti nota obtinuta: ");
    scanf("%d", &nota);

    if (nota >= 9) {
        printf("Calificativ: Excelent\n");
    } else if (nota >= 7) {
        printf("Calificativ: Bun\n");
    } else if (nota >= 5) {
        printf("Calificativ: Suficient\n");
    } else {
        printf("Calificativ: Insuficient\n");
    }

    return 0;
}
