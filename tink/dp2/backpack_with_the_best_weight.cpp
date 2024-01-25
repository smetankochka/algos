//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> wt(N);
    for (int i = 0; i < N; i++) {
        cin >> wt[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(W + 1));
    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < wt[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + wt[i - 1], dp[i - 1][j]);
            }
        }
    }
    cout <<  dp[N][W];
    return 0;
}
