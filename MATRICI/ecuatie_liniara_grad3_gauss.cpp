#include <iostream>
#include <iomanip>
#include <cmath> // Include această linie pentru a folosi fabs
using namespace std;

void gaussElimination(float matrix[3][4]) {
    for (int i = 0; i < 3; i++) {
        // Căutăm un pivot
        for (int j = i + 1; j < 3; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[i][i])) {
                for (int k = 0; k < 4; k++) {
                    swap(matrix[i][k], matrix[j][k]);
                }
            }
        }

        // Eliminare
        for (int j = i + 1; j < 3; j++) {
            float factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < 4; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Soluțiile
    float solution[3];
    for (int i = 2; i >= 0; i--) {
        solution[i] = matrix[i][3]; // Ultimul termen este termenul liber
        for (int j = i + 1; j < 3; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Afișarea soluțiilor
    cout << "Solutiile sistemului de ecuatii sunt:\n";
    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << solution[i] << endl;
    }
}

int main() {
    float matrix[3][4]; // Matricea extinsă (3x3 + 1 coloană pentru termenii liberi)

    // Introducerea coeficientilor sistemului de ecuații
    cout << "Introduceti coeficientii pentru sistemul de ecuatii liniare (3 ecuatii, 3 necunoscute):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Coeficient [rand " << i + 1 << ", coloana " << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
        cout << "Termen liber [rand " << i + 1 << "]: ";
        cin >> matrix[i][3]; // Termenul liber
    }

    // Rezolvarea sistemului
    gaussElimination(matrix);
    system("pause");
    return 0;
}
