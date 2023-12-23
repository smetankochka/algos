#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == -1 || (i == 0 && j == 0)) {
                dp[i][j] = table[i][j];
            } else if (i == 0) {
                if (dp[i][j - 1] == -1) {
                    dp[i][j] = -1;
                } else {
                    dp[i][j] = dp[i][j - 1] + table[i][j];
                }
            } else if (j == 0) {
                if (dp[i - 1][j] == -1) {
                    dp[i][j] = -1;
                } else {
                    dp[i][j] = dp[i - 1][j] + table[i][j];
                }
            } else {
                if (dp[i][j - 1] == dp[i - 1][j] && dp[i - 1][j - 1] == dp[i - 1][j] && dp[i][j - 1] == -1) {
                    dp[i][j] = -1;
                } else {
                    tmp = 1e9;
                    if (dp[i][j - 1] != -1) {
                        tmp = min(tmp, dp[i][j - 1]);
                    }
                    if (dp[i - 1][j - 1] != -1) {
                        tmp = min(tmp, dp[i - 1][j - 1]);
                    }
                    if (dp[i - 1][j] != -1) {
                        tmp = min(tmp, dp[i - 1][j]);
                    }
                    dp[i][j] = table[i][j] + tmp;
                }

/*                if (dp[i][j - 1] != -1) {
                    dp[i][j] = min(dp[i][j], table[i][j - 1] + table[i][j]);
                }
                if (dp[i - 1][j - 1] != -1) {
                    dp[i][j] = min(dp[i][j], table[i - 1][j - 1] + table[i][j]);
                }
                if (dp[i - 1][j] != -1) {
                    dp[i][j] = min(dp[i][j], table[i - 1][j] + table[i][j]);
                }*/
            }
        }
        cout << "\n";
    }
    cout << dp[n - 1][m - 1];
    return 0;
}