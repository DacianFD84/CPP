#include <stdio.h>

int main() {
    int i;

    printf("Numerele de la 1 la 5 sunt:\n");

    // Structură iterativă cu 'for'
    for (i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}


/* În cazul for (i = 1; i <= 5; i++):
Inițializarea (i = 1):

Se inițializează variabila i cu valoarea 1.
Acesta este punctul de plecare al buclei.

Condiția (i <= 5):

Bucla continuă să ruleze atâta timp cât condiția este adevărată (în acest caz, cât timp i este mai mic sau egal cu 5).
Dacă condiția devine falsă, bucla se oprește.
Incrementarea (i++):

După fiecare iterație, valoarea lui i crește cu 1 (echivalent cu i = i + 1).
i++ este operatorul de incrementare post-fixată.
Corpul buclei:

Codul dintre acolade {} se execută la fiecare iterație. */

/*

for (inițializare; condiție; incrementare) {
    // codul care se execută
}

*/
