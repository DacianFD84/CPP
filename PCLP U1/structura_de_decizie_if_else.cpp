#include <iostream>

int main() {
    int numar = 7;

    if (numar % 2 == 0) {  // Verificăm dacă numărul este par
        std::cout << numar << " este par." << std::endl;
    } else {
        std::cout << numar << " este impar." << std::endl;
    }
    system("pause");
    return 0;
}
