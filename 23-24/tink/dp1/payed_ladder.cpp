#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    cin >> dp[1];
    for (int i = 2; i <= n; i++) {
        cin >> dp[i];
        dp[i] += dp[i - 1] < dp[i - 2] ? dp[i - 1] : dp[i - 2];
    }
    cout << dp[n];
}