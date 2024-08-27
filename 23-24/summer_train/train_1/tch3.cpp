// powered by smetanka on 09.06.2024

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int f1 = 1, f2 = 1, mod = 1e6 + 3, n, f;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        f = f1;
        f1 = f2;
        f2 = (f1 + f) % mod;
    }

    cout << f2;

    return 0;
}