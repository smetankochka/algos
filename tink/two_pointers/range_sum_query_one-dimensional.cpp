#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n, q;
    cin >> n;
    vector<ll> pref(n + 1, (ll)0);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
    }
}
