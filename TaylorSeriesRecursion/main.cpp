#include <iostream>

using namespace std;

double e(double x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1.0;
    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;
}

int main() {
    cout << "Hello, World!" << std::endl;
    cout << e(1, 70000) << endl;
    return 0;
}
