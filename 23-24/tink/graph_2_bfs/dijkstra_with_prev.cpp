#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int n, s, t, v, m, u, w;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        g[v - 1].push_back({w, u - 1});
        g[u - 1].push_back({w, v - 1});
    }
    s--;
    t--;
    vector<int> dist(n, 1e9);
    set<pair<int, int>> q;
    dist[s] = 0;
    q.insert({0, s});
    while (!q.empty()) {
        v = q.begin()->second;
        q.erase(q.begin());
        for (auto [w, u] : g[v]) {
            if (dist[u] > dist[v] + w) {
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
        }
    }
    cout << dist[t];
    return 0;
}