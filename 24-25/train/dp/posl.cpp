#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 2);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = i % 2 == 0 ? dp[i / 2] + dp[i / 2 - 1] : dp[(i - 1) / 2] - dp[(i - 1) / 2 - 1];
    }

    cout << dp[n];

    return 0;
}