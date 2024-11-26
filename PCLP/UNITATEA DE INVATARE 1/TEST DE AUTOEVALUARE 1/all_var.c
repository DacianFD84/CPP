#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variabile de bază
    int numar_intreg = 10;            // Număr întreg
    float numar_real = 3.14f;         // Număr real cu precizie simplă
    double numar_real_mare = 2.71828; // Număr real cu precizie dublă
    char caracter = 'A';              // Caracter unic
    bool valoare_booleana = false;     // Valoare booleană (true/false)

    // Variabile semnate și nesemnate
    unsigned int numar_fara_semn = -25;  // Număr pozitiv (fără semn)
    signed int numar_cu_semn = -15;     // Număr întreg cu semn
    short int numar_scurt = 32000;      // Număr întreg scurt
    long int numar_lung = 1000000L;     // Număr întreg lung
    long long int numar_foarte_lung = 12345678901234LL; // Număr foarte lung

    // Pointeri
    int* pointer = &numar_intreg;

    // Afișare valori
    printf("Tipuri de variabile in C:\n");
    printf("1. int (numar intreg): %d\n", numar_intreg);
    printf("2. float (numar real cu precizie simpla): %.2f\n", numar_real);
    printf("3. double (numar real cu precizie dubla): %.5lf\n", numar_real_mare);
    printf("4. char (caracter): %c\n", caracter);
    printf("5. bool (valoare booleana): %s\n", valoare_booleana ? "true" : "false");
    printf("6. unsigned int (numar fara semn): %u\n", numar_fara_semn);
    printf("7. signed int (numar cu semn): %d\n", numar_cu_semn);
    printf("8. short int (numar scurt): %hd\n", numar_scurt);
    printf("9. long int (numar lung): %ld\n", numar_lung);
    printf("10. long long int (numar foarte lung): %lld\n", numar_foarte_lung);
    printf("11. Pointer (adresa lui numar_intreg): %p\n", (void*)pointer);
    printf("12. Valoarea la care pointeaza pointerul: %d\n", *pointer);

    return 0;
}


/* Afișare:

%d: afișează un număr întreg cu semn.
%u: afișează un număr întreg fără semn.
%f și %lf: afișează numere reale (float/double).
%c: afișează un caracter.
%s: afișează un șir de caractere.
%p: afișează o adresă de memorie. */
