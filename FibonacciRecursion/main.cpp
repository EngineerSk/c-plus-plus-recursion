#include <iostream>
#include <vector>

using namespace std;

int iterativeFibonacci(int n) {
    int first = 0, second = 1, sum = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; ++i) {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int recursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return recursiveFibonacci(n - 2) + recursiveFibonacci(n - 1);
}

int recursiveMemoizationFibonacci(int n, int *fibCache) {
    if (n <= 1)return n;
    if (fibCache[n - 1] == -1)
        fibCache[n - 1] = recursiveMemoizationFibonacci(n - 1, fibCache);
    if (fibCache[n - 2] == -1)
        fibCache[n - 2] = recursiveMemoizationFibonacci(n - 2, fibCache);
    return fibCache[n - 1] + fibCache[n - 2];
}

int main() {
    int n = 10;
    int fib[n];
    for (int i = 0; i < n; ++i) {
        fib[i] = -1;
    }
    cout << "iterative fibonacci: " << iterativeFibonacci(n) << endl;
    cout << "Recursive Fibonacci: " << recursiveFibonacci(n) << endl;
    cout << "Recursive Fibonacci Memoization: " << recursiveMemoizationFibonacci(n, fib) << endl;
    return 0;
}
