#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    vector<int> a;
    vector<int> ans;
    while (t--) {
        cin >> n;
        a.resize(n);
        ans.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int last_down = a[0], last_up, last_zap = 0, cur_up;
        cin >> last_up;
        bool last_is_up = false;
        for (int i = 1; i < n; i++) {
            cin >> cur_up;
            if (last_up < a[i]) {
                while (last_zap != i) {
                    ans[last_zap] = last_up;
                    last_zap++;
                }
                last_down = a[i];
                last_up = cur_up;
                last_is_up = true;
            } else if (last_down > cur_up) {
                while (last_zap != i) {
                    ans[last_zap] = last_down;
                    last_zap++;
                }
                last_down = a[i];
                last_up = cur_up;
                last_is_up = false;
            } else {
                last_down = max(last_down, a[i]);
                last_up = min(last_up, cur_up);
            }
        }
        while (last_zap != n) {
            if (last_is_up) {
                ans[last_zap] = last_down;
            } else {
                ans[last_zap] = last_up;
            }
            last_zap++;
        }
        ll s = 0;
        for (int i = 1; i < n; i++) {
            s += abs(ans[i] - ans[i - 1]);
        }
        cout << s << "\n";
        for (int answer : ans) {
            cout << answer << " ";
        }
        cout << "\n";
    }


    return 0;
}