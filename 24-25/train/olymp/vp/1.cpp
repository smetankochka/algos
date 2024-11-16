#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, cur = 0, need, first, firstpereh = 0;
    cin >> n >> k;
    vector<ll> dp(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> need;
        need--;
        dp[i] = dp[i - 1];
        if (i == 0) {
            first = need;
            if (need > cur) {
                firstpereh = need - cur;
            } else if (need < cur) {
                firstpereh = n - cur + need;
            }
            continue;
        }
        if (need > cur) {
            dp[i] += need - cur;
        } else if (need < cur) {
            dp[i] += n - cur + need;
        }
        cur = need;
    }
    ll pereh = 0;
    if (first > need) {
        pereh = first - need;
    } else if (first < need) {
        pereh = first - cur + n;
    }
    ll koef = k / n;
    ll ans = koef * dp[n - 1] + firstpereh;
    k -= koef * n;
    if (k > 0) {
        ans += koef * pereh;
        ans += dp[k - 1];
    } else {
        ans += (koef - 1) * pereh;
    }
    cout << ans;
    return 0;
}