#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, l, r;
    ll s = 0;
    cin >> n >> q;
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }

    while(q--) {
        cin >> l >> r;
        s += pref[r] - pref[l - 1];
    }
    
    cout << s;
    return 0;
}