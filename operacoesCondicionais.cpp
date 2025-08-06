#include <iostream>

int main () {
    int number1;
    int number2;

    std::cout << "Digite o primeiro número: ";
    std::cin >> number1;
    std::cout << "Digite o segundo número: ";
    std::cin >> number2;

    if(number1 == number2) {
        std::cout << number1 << " é igual a " << number2 << std::endl;
    }
    if(number1 != number2) {
        std::cout << number1 << " é diferente de " << number2 << std::endl;
    }
    if(number1 < number2) {
        std::cout << number1 << " é menor que " << number2 << std::endl;
    }
    if(number1 > number2) {
        std::cout << number1 << " é maior que " << number2 << std::endl;
    }

    return 0;
}