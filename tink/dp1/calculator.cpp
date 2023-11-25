#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cur = n;
    vector<int> dp(n + 1, 1);
    vector<int> prev(n + 1, 1);
    prev[2] = 2;
    prev[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = 2;
        }
    }
    deque<int> ans;
    for (int i = 0; i < dp[n]; i++) {
        ans.push_front(prev[cur]);
        if (prev[cur] == 1) {
            cur--;
        } else {
            cur /= prev[cur];
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
}