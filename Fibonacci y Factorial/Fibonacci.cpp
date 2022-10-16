#include <iostream>

using namespace std;

int fibo(int in) {
    // cout << "Entering to compute f" << i << endl;

    // Base step
    if(in<=2) return 1;

    // Induction
    return fibo(in-1) + fibo(in-2);
}

int fact(int index) {
    if(index <= 0) return 1;

    return index*fact(index-1);
}


int main() {
    cout << fibo(8) << endl;

    cout << fact(3) << endl;

    return 0;
}