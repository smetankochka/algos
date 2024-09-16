#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
ll count = 0, t;

ll euclidean(ll n, ll m) {
    while (m != 0) {
        t = m;
        count += n / m;
        m = n % m;
        n = t;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;
    ll c = euclidean(a, b);
    cout << count << "\n";
    return 0;
}