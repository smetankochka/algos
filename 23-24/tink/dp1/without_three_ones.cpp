#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> dp(40);
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n];
    return 0;
}