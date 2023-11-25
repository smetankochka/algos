#include <iostream>
using namespace std;
int main() {
    int n, i, ans = 0;
    cin >> n;
    int dp[20][3];
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] = dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    }
    for (i = 0; i < 3; i++) {
        ans += dp[n - 1][i];
    }
    cout << ans;
    return 0;
}