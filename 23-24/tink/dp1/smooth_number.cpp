#include <iostream>
#include <vector>
using namespace std;

long long countSmoothNumbers(int n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] = dp[i - 1][max(0, j - 1)] + dp[i - 1][j] + dp[i - 1][min(9, j + 1)];
        }
    }
    long long total = 0;
    for (int i = 0; i <= 9; ++i) {
        total += dp[n][i];
    }
    total -= dp[n][0];

    return total;
}

int main() {
    int n;
    cin >> n;
    long long result = countSmoothNumbers(n);
    cout << result << endl;
    return 0;
}
