#include <iostream>

using namespace std;

void towerOfHanoi(int n, int A, int B, int C) {
    if (n > 0) {
        towerOfHanoi(n - 1, A, C, B);
        cout << "(" << A << ", " << C << ")" << endl;
        towerOfHanoi(n - 1, B, A, C);
    }
}

int main() {
    towerOfHanoi(32, 1, 2, 3);
    return 0;
}
