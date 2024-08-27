// powered by smetanka on 09.06.2024

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, m = 1e6 + 7;

    cin >> a >> b;

    a = (a * a) % m;
    b = (b * b) % m;
    a = (a - b) % m;
    if (a < 0) {
        a += m;
    }
    cout << a;

    return 0;
}