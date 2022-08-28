#include <iostream>

using namespace std;

static int counter = 0;

int fun(int n) {
    cout<<++counter<<" "<<n<<endl;
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
}

int main() {

    fun(96);
    return 0;
}
