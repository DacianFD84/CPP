#include <iostream>
using namespace std;

int main() {
    float matrix[2][2], inverse[2][2], product[2][2];
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

    // Verificarea dacă matricea este inversabilă
    if (determinant == 0) {
        cout << "Matricea nu este inversabilă (determinantul este 0).\n";
    } else {
        // Calculul inversului matricei
        inverse[0][0] = matrix[1][1] / determinant;
        inverse[0][1] = -matrix[0][1] / determinant;
        inverse[1][0] = -matrix[1][0] / determinant;
        inverse[1][1] = matrix[0][0] / determinant;

        // Afișarea rezultatului
        cout << "\nMatricea inversă este:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << inverse[i][j] << " ";
            }
            cout << endl;
        }

        // Calcularea produsului dintre matricea inițială și inversa
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                product[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    product[i][j] += matrix[i][k] * inverse[k][j];
                }
            }
        }

        // Afișarea produsului
        cout << "\nProdusul dintre matricea originală și matricea inversă este:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
