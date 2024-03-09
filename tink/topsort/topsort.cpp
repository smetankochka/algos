//
// Created by smetanka on 09.03.24.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n, m, cur;
    cin >> n >> m;
    vector<pair<int, int>> ribs(m);
    vector<int> topsort(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> ribs[i].first >> ribs[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> cur;
        topsort[cur] = i;
    }
    for (pair<int, int>& rib : ribs) {
        if (topsort[rib.first] > topsort[rib.second]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}