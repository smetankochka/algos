#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using ll = long long;
using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k, h, w;
    bool flag = false;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        cin >> n >> m >> k;
        h = 0, w = 0;
        vector<pair<int, int>> dp(s.size() + 1);
        flag = false;
        dp[0] = make_pair(0, 0);
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '2') {
                h++;
            } else if (s[i] == '4') {
                w--;
            } else if (s[i] == '6') {
                w++;
            } else {
                h--;
            }
            dp[i + 1] = make_pair(h, w);
            if (i + 1 >= k && dp[i + 1].first - dp[i + 1 - k].first == m && dp[i + 1].second - dp[i  + 1 - k].second == n) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}