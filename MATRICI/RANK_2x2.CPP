#include <iostream>
using namespace std;

int main() {
    float matrix[2][2];
    float determinant;

    // Introducerea elementelor matricei
    cout << "Introduceți valorile pentru matricea 2x2:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Calculul determinantului
    determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    // Determinarea rangului
    int rank;
    if (determinant != 0) {
        rank = 2; // Rangul este 2 dacă determinantul este diferit de zero
    } else {
        // Verificăm dacă oricare linie este non-zero pentru a stabili rangul 1
        if (matrix[0][0] != 0 || matrix[0][1] != 0 || matrix[1][0] != 0 || matrix[1][1] != 0) {
            rank = 1; // Rangul este 1 dacă există cel puțin o linie non-zero
        } else {
            rank = 0; // Rangul este 0 dacă toate elementele sunt zero
        }
    }

    // Afișarea rezultatului
    cout << "Rangul matricei este: " << rank << endl;
    system("pause");
    return 0;
}
