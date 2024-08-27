#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n + 1, vector<ll> (m + 1, (ll)0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll aij;
            cin >> aij;
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j] + aij - matrix[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        cout << matrix[rx][ry] - matrix[rx][ly - 1] - matrix[lx - 1][ry] + matrix[lx - 1][ly - 1] << " ";
    }
    return 0;
}
