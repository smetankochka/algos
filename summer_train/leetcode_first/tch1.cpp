// powered by smetanka on 09.06.2024

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m = 1e6 + 3, f = 1;

    cin >> n;

    if (n >= m) {
        cout << 0;
        return 0;
    }

    for (ll i = 2; i <= n; i++) {
        f = (f * i) % m;
    }

    cout << f;

    return 0;
}