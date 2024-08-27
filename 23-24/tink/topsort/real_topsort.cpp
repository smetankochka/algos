//
// Created by smetanka on 09.03.24.
//
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

ll bfs(int v, vector<vector<int>>& g, vector<int>& ts, vector<int>& ans, vector<bool>& used) {
    ll fsh = ts[v];
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            fsh += bfs(u, g, ts, ans, used);
        }
    }
    ans.push_back(v + 1);
    return fsh;
}

int main() {
    int n, m, cur;
    cin >> n;
    vector<int> ts(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n ; i++) {cin >> ts[i];}
    for (int i = 0; i < n; i++) {
        cin >> m;
        while (m--) {
            cin >> cur;
            g[i].push_back(cur - 1);
        }
    }
    vector<int> ans;
    vector<bool> used(n, false);
    cout << bfs(0, g, ts, ans, used) << " " << ans.size() << "\n";
    for (int u : ans) {
        cout << u << " ";
    }
}