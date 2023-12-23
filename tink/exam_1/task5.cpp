#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ll a, b, c, i, j;
    cin >> a >> b >> c >> i >> j;
    ll d = lcm(a, lcm(b, c));
    ll cnt = j / d - (i - 1) / d;
    cout << cnt;
    return 0;
}
