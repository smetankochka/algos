#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> pref_difference(n + 1, vector<ll> (m + 1, 0));
    while (q--) {
        int lx, ly, rx, ry;
        ll d;
        cin >> lx >> ly >> rx >> ry >> d;
        pref_difference[lx][ly] += d;
        if (ry + 1 <= m) {pref_difference[lx][ry + 1] -= d;}
        if (rx + 1 <= n) {pref_difference[rx + 1][ly] -= d;}
        if (ry + 1 <= m && rx + 1 <= n) {pref_difference[rx + 1][ry + 1] += d;}
    }
    vector<vector<ll>> pref_sum(n + 1, vector<ll> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref_sum[i][j] = pref_sum[i][j - 1] + pref_sum[i - 1][j] - pref_sum[i - 1][j - 1] + pref_difference[i][j];
            cout << pref_sum[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
