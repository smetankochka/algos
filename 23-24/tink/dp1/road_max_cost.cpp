#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<char>> prev(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = table[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + table[i][j];
                prev[i][j] = 'R';
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + table[i][j];
                prev[i][j] = 'D';
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + table[i][j];
                    prev[i][j] = 'D';
                } else {
                    dp[i][j] = dp[i][j - 1] + table[i][j];
                    prev[i][j] = 'R';
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
    int curi = n - 1, curj = m - 1;
    string path = "";
    while (curi > 0 || curj > 0) {
        path = prev[curi][curj] + path;
        if (prev[curi][curj] == 'D') {
            curi--;
        } else {
            curj--;
        }
    }
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}