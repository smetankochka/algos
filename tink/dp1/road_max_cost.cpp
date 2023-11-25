#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
int main() {
    int n, m;
    ll cur;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
    vector<vector<char>> prevcommand(n + 1, vector<char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cur;
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + cur;
                prevcommand[i][j] = 'D';
            } else {
                dp[i][j] = dp[i][j - 1] + cur;
                prevcommand[i][j] = 'R';
            }
        }
    }
    cout << dp[n][m] << "\n";
    size_t curi = n, curj = m;
    for (int i = 0; i < n + m - 2; i++) {
        cout << prevcommand[curi][curj] << " ";
        if (prevcommand[curi][curj] == 'D') {
            curi--;
        } else {
            curj--;
        }
    }
    return 0;
}