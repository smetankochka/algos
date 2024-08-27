//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string f, s;
    cin >> f >> s;
    vector<vector<int>> dp(f.size() + 1, vector<int> (s.size() + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= f.size(); i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i <= s.size(); i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i <= f.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            dp[i][j] = f[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }
    cout << dp[f.size()][s.size()];
}