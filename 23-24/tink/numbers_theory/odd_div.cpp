#include <iostream>
using namespace std;

long long extendedGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long findModularInverse(long long a, long long m) {
    long long x, y;
    long long gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    long long a, m;
    cin >> a >> m;
    long long inverse = findModularInverse(a, m);
    cout << inverse << std::endl;
    return 0;
}