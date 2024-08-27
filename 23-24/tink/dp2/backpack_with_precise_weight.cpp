//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> elem(n);
    for (int i = 0; i < n; i++) {cin >> elem[i];}
    vector<vector<bool>> dp(n + 1, vector<bool> (w + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j] || (j >= elem[i - 1] && dp[i - 1][j - elem[i - 1]]);
        }
    }
    if (dp[n][w]) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}