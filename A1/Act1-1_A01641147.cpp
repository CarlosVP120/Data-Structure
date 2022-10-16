#include <iostream>

using namespace std;

// Carlos Alberto Veryan Peña A01641147

int sum(int x) {
    // inicializa el valor en 0
    int val = 0;

    // Se hace un cíclo desde 1 hasta x
    for(int i = 1; i <= x; i = i + 1)
    {
        // Al valor se le va agregando cada número (ej. 1+2+3+...+n)
        val += i;
    }
    // Regresa el valor
    return val;
}

int recursiveSum(int x) {
    // Evaluar si x es menor o igual a 0.
    if (x <= 0) return 0;

    // Utilizar recursividad para obtener la suma recursiva hasa x.
    return x + recursiveSum(x-1);
}

int directSum(int x) {
    // Se evalua si x es mayor a 0
    if (x > 0)
    {
        // Se regresa la fórmula matemática con el valor x sustituido en ella.
        return ((x*(x+1))/2);
    };

    return 0;
}

int main() {

    // Prueba Sum()
    cout << endl << "Prueba Sum()" << endl << "------------" << endl;
    cout << "Valor: 5 -> " << sum(5) << endl;
    cout << "Valor: 4 -> " << sum(4) << endl;
    cout << "Valor: 3 -> " << sum(3) << endl;
    cout << "Valor: 2 -> " << sum(2) << endl << endl;

    // Prueba recursiveSum()
    cout << "Prueba recursiveSum()" << endl << "------------" << endl;
    cout << "Valor: 6 -> " << recursiveSum(6) << endl;
    cout << "Valor: 7 -> " << recursiveSum(7) << endl;
    cout << "Valor: 8 -> " << recursiveSum(8) << endl;
    cout << "Valor: 9 -> " << recursiveSum(9) << endl << endl;

    // Prueba directSum()
    cout << "Prueba directSum()" << endl << "------------" << endl;
    cout << "Valor: 10 -> " << directSum(10) << endl;
    cout << "Valor: 11 -> " << directSum(11) << endl;
    cout << "Valor: 12 -> " << directSum(12) << endl;
    cout << "Valor: 13 -> " << directSum(13) << endl << endl;

    return 0;
}