//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {cin >> f[i];}
    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {cin >> s[i];}
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (f[i - 1] == s[j - 1]) {dp[i][j]++;}
        }
    }
    cout << dp[n][m];
}