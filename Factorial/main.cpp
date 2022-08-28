#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

int iterativeFactorial(int n) {
    if (n == 0)
        return 1;
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    cout << "Recursive factorial of 15: " << factorial(15) << endl;
    cout << "Iterative factorial of 31: " << iterativeFactorial(31) << endl;
    return 0;
}
