#include <iostream>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    ll f = 1, s = 1, d;
    for (int i = 0; i < n; i++) {
        d = f + s;
        f = s;
        s = d;
    }
    cout << s;
    return 0;
}