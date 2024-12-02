#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>


using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, l, c;
    cin >> n >> k >> l;
    vector<ll> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i < n; i++) {
        if (abs(heights[i] - heights[i - 1]) > l) {
            dp[i + 1] = dp[i] + 1;
        } else {
            dp[i + 1] = dp[i];
        }
        c = 0;
        if (i > 1 && heights[i - 2] > l) {
            c = 1;
        }
        if (heights[i] > l) {
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + 1 + c);
        } else {
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + c);
        }
    }
    if (dp[n] <= k || dp[n - 2] <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
