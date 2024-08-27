#include <iostream>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    a = gcd(a, b);
    n -= 2;
    while (n--) {
        cin >> b;
        a = gcd(a, b);
    }
    cout << a;
    return 0;
}