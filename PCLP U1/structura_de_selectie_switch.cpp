#include <iostream>

int main() {
    int zi = 3;

    switch (zi) {
        case 1:
            std::cout << "Luni" << std::endl;
            break;
        case 2:
            std::cout << "Marti" << std::endl;
            break;
        case 3:
            std::cout << "Miercuri" << std::endl;
            break;
        case 4:
            std::cout << "Joi" << std::endl;
            break;
        case 5:
            std::cout << "Vineri" << std::endl;
            break;
        default:
            std::cout << "Weekend!" << std::endl;
    }
    system("pause");
    return 0;
}
