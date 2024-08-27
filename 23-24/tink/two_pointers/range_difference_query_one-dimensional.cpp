#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> pref_difference(n + 1, (ll)0);
    while (q--) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        pref_difference[l - 1] -= d;
        pref_difference[r] += d;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans -= pref_difference[i];
        cout << ans << " ";
    }
    return 0;
}
