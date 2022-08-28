#include <iostream>

using namespace std;

int sum(int n) {
    if (n == 0)
        return n;
    return sum(n - 1) + n;
}

int iterativeSum(int n) {
    if (n == 0)
        return n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int standardSumOfNaturalNumber(int n) {
    return n * (n + 1) / 2;
}

int main() {
    cout << "Recursive sum of 500: " << sum(500) << endl;
    cout << "Iterative sum of 500: " << iterativeSum(500) << endl;
    cout << "Standard sum of 100000: " << standardSumOfNaturalNumber(100000) << endl;
    return 0;
}
