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
    vector<int> val(N, 1);
    vector<vector<int>> dp(N + 1, vector<int>(W + 1));
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout <<  dp[N][W];
    return 0;
}
