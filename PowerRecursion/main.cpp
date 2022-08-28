#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getIndexValueFromMapKeys(int indexKey);

bool getKeyIndexPosition(int indexKey);

map<int, long long> powerProductMap;
vector<int> mapKeys;

int power(int m, int n) {
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}

int logarithmicRecursivePower(int m, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(m * m, n / 2);
    return m * power(m * m, (n - 1) / 2);
}

int iterativePower(int m, int n) {
    if (n == 0)
        return 1;
    int powerProduct = 1;
    if (n % 2 == 1)
        powerProduct *= m;
    int numOfIterations = n / 2;
    for (int i = 0; i < numOfIterations; ++i) {
        powerProduct *= m * m;
    }

    return powerProduct;
}

long long int logarithmicIterativePower(long long int m, int n) {
    if (n == 0)
        return 1;
    static long long int powerProduct = 1;
    static long long int oddProductValue = 1;
    if (n % 2 == 1) {
        oddProductValue *= m;
        --n;
    }
    cout << "odd power product" << powerProduct << endl;
    if (n - 2 >= 0) {
        powerProduct = m * m;
        cout << "even power product" << powerProduct << endl;
    }
    if (n <= 3)
        return powerProduct *= oddProductValue;

    powerProductMap.insert(pair<int, long long int>(2, powerProduct));
    mapKeys = {2};
    int i = 4;
    while (n - i >= 0) {

        if (n - i >= 0) {
            powerProduct *= powerProduct;
            powerProductMap.insert(pair<int, long long int>(i, powerProduct));
            mapKeys.push_back(i);
        }
        if (n - i == 0)
            return powerProduct * oddProductValue;
        if ((n - (i * 2)) < 0) {
            int productMapIndexKey = getIndexValueFromMapKeys(n - i);
            if (productMapIndexKey == n - i) {
                powerProduct *= (powerProductMap[n - i] * oddProductValue);
            } else {
                long long int powerProductMultiplier = 1;
                int currentPowerProductMapKey = (n - i);
                int keyIndexPosition = getKeyIndexPosition(currentPowerProductMapKey);
                while (mapKeys[keyIndexPosition] != currentPowerProductMapKey) {
                    productMapIndexKey = getIndexValueFromMapKeys(currentPowerProductMapKey);
                    if (productMapIndexKey == currentPowerProductMapKey) {
                        break;
                    }
                    if (productMapIndexKey > currentPowerProductMapKey) {
                        currentPowerProductMapKey = currentPowerProductMapKey - mapKeys[keyIndexPosition - 1];
                        powerProductMultiplier *= powerProductMap[mapKeys[keyIndexPosition - 1]];
                    } else {
                        currentPowerProductMapKey = currentPowerProductMapKey - mapKeys[keyIndexPosition];
                        powerProductMultiplier *= powerProductMap[mapKeys[keyIndexPosition]];
                    }
                    keyIndexPosition = getKeyIndexPosition(currentPowerProductMapKey);
                }
                powerProductMultiplier *= powerProductMap[productMapIndexKey];
                powerProduct *= (powerProductMultiplier *
                                 oddProductValue);
            }
            return powerProduct;
        }
        i *= 2;
    }

    return powerProduct;
}

bool getKeyIndexPosition(int indexKey) {
    unsigned long l = 0;
    unsigned long r = mapKeys.size();
    cout << "binary block" << endl;
    for (auto const i: mapKeys) {
        cout << i << " ";
    }
    cout << endl;
    int currentValue;
    while (l <= r) {
        unsigned long mid = (l + r) / 2;
        currentValue = mapKeys[mid];
        if (indexKey == currentValue) {
            return mid;
        } else if (indexKey > currentValue) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if (r < l || l > r || l > mapKeys.size() - 1)
            return mid;
    }
    return -1;
}

int getIndexValueFromMapKeys(int indexKey) {
    unsigned long l = 0;
    unsigned long r = mapKeys.size();
    cout << "binary block" << endl;
    for (auto const i: mapKeys) {
        cout << i << " ";
    }
    cout << endl;
    int currentValue = 0;
    while (l <= r) {
        unsigned long mid = (l + r) / 2;
        currentValue = mapKeys[mid];
        if (indexKey == currentValue) {
            return indexKey;
        } else if (indexKey > currentValue) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if (r < l || l > r || l > mapKeys.size() - 1)
            return currentValue;
    }
    return currentValue;
}

int main() {
    int m = 2, n = 60;
    cout << m << " ^ " << n << ": " << power(m, n) << endl;
    cout << "logarithmic power of " << m << " ^ " << n << ": " << logarithmicRecursivePower(m, n) << endl;
    static long long int logarithmicPower = logarithmicIterativePower(m, n);
    cout << "logarithmic iterative power of " << m << " ^ " << n << ": " << logarithmicPower << endl;
    return 0;
}
