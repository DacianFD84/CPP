#include <iostream>
using namespace std;

int main() {
    int A[2][2];
    
    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }
    
    // Calculul determinantului
    int determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    
    // Afișarea determinantului
    cout << "\nDeterminantul matricei A este: " << determinant << endl;
    system("pause");
    return 0;
}
