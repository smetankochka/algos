#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool comp(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - a.second) > abs(b.first - b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, f_count, s_count;
    ll ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> mas(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> mas[i].first;
        }
        for (int i = 0; i < 2 * n; i++) {
            cin >> mas[i].second;
        }
        sort(mas.begin(), mas.end(), comp);
        f_count = 0, s_count = 0, ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (f_count < n && s_count < n) {
                if (mas[i].first < mas[i].second) {
                    ans += mas[i].first;
                    f_count++;
                } else {
                    ans += mas[i].second;
                    s_count++;
                }
            } else if (f_count < n) {
                ans += mas[i].first;
                f_count++;
            } else {
                ans += mas[i].second;
                s_count++;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}