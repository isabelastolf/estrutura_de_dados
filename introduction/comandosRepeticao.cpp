#include <iostream>
#include <limits>

using namespace std;

void sumElements();
void sumCounter();

int main() {

    int chosenAction = 0;
    
    while(chosenAction != 1 && chosenAction != 2) {
        cout << "Escolha a funcao desejada: " << endl;
        cout << "Digite (1) para sumElements (soma 10 elementos)" << endl;
        cout << "Digite (2) para sumCounter (total de operacoes executadas até totalizar 100)" << endl;
        cout << "Digite (0) para sair do programa." << endl;
        cin >> chosenAction;

        if (chosenAction == 1)
            sumElements();
        else if (chosenAction == 2)
            sumCounter();
        else if (chosenAction == 0)
            break;
        else
            cout << " -> Escolha inválida;" << endl;
    }

    return 0;
}

void sumElements() {
    int number1;
    int counter = 1;
    int amount = 0;

    while (counter < 11) {
        cout << "Digite um número (elemento " << counter << "o)" << endl;
        cin >> number1;

        if(cin.fail()){
            cout << "Número inválido. Insira um número inteiro em formato numérico." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else {
            if(number1)
                amount = amount + number1;
            counter++;
    
            if(counter == 11)
                cout << "Total inserido: " << amount << "." << endl;
        }
    }
    return;
}

void sumCounter() {
    int number1;
    int counter = 0;
    int amount = 0;

    while (amount < 100){
        cout << "Digite um número (total atual: " << amount << ")" << endl;
        cin >> number1;

        if (number1 < 0) {
            cout << "Número inválido. Insira um número natural em formato numérico." << endl;
        }
        else if (cin.fail()) {
            cout << "Número inválido. Insira um número natural em formato numérico." << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            if (number1) {
                amount += number1;
            }
        counter++;

            if (amount >= 100){
                cout << "Total de operacoes executadas: " << counter << "." << endl;
            }
        }
    }
    return;
}