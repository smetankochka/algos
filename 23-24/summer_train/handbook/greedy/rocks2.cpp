// powered by smetanka on 21.07.2024

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

    vector<vector<bool>> dp(n + 2, vector<bool> (m + 2, false));
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[2][0] = 1;
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[1][2] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j]) {
                continue;
            }
            if ((i - 1 >= 0 && !dp[i - 1][j]) || (j - 1 >= 0 && !dp[i][j - 1])) {
                dp[i][j] = 1;
                continue;
            }
            if ((i - 2 >= 0 && !dp[i - 2][j]) || (j - 2 >= 0 && !dp[i][j - 2])) {
                dp[i][j] = 1;
                continue;
            }
            if ((i - 2 >= 0 && j - 1 >= 0 && !dp[i - 2][j - 1]) || (j - 2 >= 0 && i - 1 >= 0 && !dp[i - 1][j - 2])) {
                dp[i][j] = 1;
                continue;
            }
        }
    }

    if (dp[n][m]) {
        cout << "Win";
    } else {
        cout << "Loose";
    }

    return 0;
}