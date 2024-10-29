#include <iostream>
using namespace std;

int main() {
    int A[3][3];

    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Calculul determinantului pentru matricea 3x3
    int determinant = 
          A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    // Afișarea determinantului
    cout << "\nDeterminantul matricei A este: " << determinant << endl;
    system("pause");
    return 0;
}
