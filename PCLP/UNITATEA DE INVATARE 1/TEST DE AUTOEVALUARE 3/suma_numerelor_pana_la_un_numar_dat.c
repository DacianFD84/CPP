#include <stdio.h>

int main() {
    int n, suma = 0;

    printf("Introduceti un numar: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        suma += i; // Adunam fiecare numar la suma
    }

    printf("Suma numerelor de la 1 la %d este: %d\n", n, suma);
    return 0;
    system("pause");
}
