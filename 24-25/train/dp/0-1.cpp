#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ull> dp(n + 3);
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}