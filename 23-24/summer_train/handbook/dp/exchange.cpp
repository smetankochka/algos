// powered by smetanka on 25.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i >= 3 && dp[i] > dp[i - 3] + 1) {
            dp[i] = dp[i - 3] + 1;
        }
        if (i >= 4 && dp[i] > dp[i - 4] + 1) {
            dp[i] = dp[i - 4] + 1;
        }
    }

    cout << dp[n];

    return 0;
}