#include <iostream>
#include <iomanip>
using namespace std;

// Funcție pentru a schimba două rânduri
void swapRows(float matrix[3][4], int row1, int row2) {
    for (int i = 0; i < 4; i++) {
        float temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// Funcție pentru a reduce matricea la forma redusă prin rânduri (RREF)
int reduceMatrix(float matrix[3][4]) {
    int rank = 0;
    for (int col = 0; col < 3; col++) {
        // Găsim un rând care are un element nenul în coloană
        int pivotRow = rank;
        while (pivotRow < 3 && matrix[pivotRow][col] == 0) {
            pivotRow++;
        }

        // Dacă am găsit un pivot
        if (pivotRow < 3) {
            if (pivotRow != rank) {
                swapRows(matrix, pivotRow, rank); // Schimbăm rândurile
            }

            // Normalizăm rândul pivot
            float pivot = matrix[rank][col];
            for (int j = 0; j < 4; j++) {
                matrix[rank][j] /= pivot; // Facem pivotul egal cu 1
            }

            // Eliminăm elementele de sub pivot
            for (int i = rank + 1; i < 3; i++) {
                float factor = matrix[i][col];
                for (int j = 0; j < 4; j++) {
                    matrix[i][j] -= factor * matrix[rank][j];
                }
            }

            rank++; // Incrementăm rangul
        }
    }
    return rank;
}

int main() {
    float matrix[3][4]; // Matricea extinsă (3x3 + 1 coloană pentru rezultatul RREF)

    // Introducerea elementelor matricei
    cout << "Introduceți valorile pentru matricea 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
            matrix[i][3] = 0; // Inițializăm a patra coloană cu 0 pentru RREF
        }
    }

    // Calcularea rangului
    int rank = reduceMatrix(matrix);

    // Afișarea rezultatului
    cout << "Rangul matricei este: " << rank << endl;
    system("pause");
    return 0;
}
