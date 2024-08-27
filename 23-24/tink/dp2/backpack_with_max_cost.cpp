//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> c(n + 1), m(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= m[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - m[i]] + c[i]);
        }
    }
    vector<int> ans;
    int i = n, j = w;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            ans.push_back(i);
            j -= m[i];
            i--;
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}