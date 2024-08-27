#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, min_y, trash;
    cin >> n;
    vector<pair<int, int>> polys(n);
    for (int i = 0; i < n; i++) {
        cin >> m;
        cin >> trash >> polys[i].first;
        m--;
        while (m--) {
            cin >> trash >> min_y;
            if (min_y < polys[i].first) {polys[i].first = min_y;}
        }
        polys[i].second = i;
    }
    sort(polys.begin(), polys.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[polys[i].second] = i;
    }
    for (int i = 0; i < n; i++) {cout << ans[i] << " ";}
}