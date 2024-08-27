#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n, m, k, q;
    ll aijt;
    cin >> n >> m >> k;
    vector<vector<vector<ll>>> cube(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int t = 1; t <= k; t++) {
                cin >> aijt;
                cube[i][j][t] =
                        aijt + cube[i][j][t - 1] + cube[i][j - 1][t] + cube[i - 1][j][t] + cube[i - 1][j - 1][t - 1];
                cube[i][j][t] -= cube[i - 1][j - 1][t] + cube[i][j - 1][t - 1] + cube[i - 1][j][t - 1];
            }
        }
    }
    cin >> q;
    while (q--) {
        int lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;
        ll ans = cube[rx][ry][rz] + cube[rx][ly - 1][lz - 1] + cube[lx - 1][ry][lz - 1] + cube[lx - 1][ly - 1][rz];
        ans -= cube[rx][ly - 1][rz] + cube[rx][ry][lz - 1] + cube[lx - 1][ry][rz] + cube[lx - 1][ly - 1][lz - 1];
        cout << ans << " ";
    }
}