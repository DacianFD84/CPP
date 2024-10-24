#include <iostream>

int main() {
    int array[5] = {1, 2, 3, 4, 5};  // Tablou de 5 elemente de tip int

    std::cout << "Elementele tabloului sunt: ";
    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << " ";  // Afișează fiecare element
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
