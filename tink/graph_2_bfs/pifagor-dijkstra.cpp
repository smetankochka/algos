#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int n, s, t, v;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i].first >> input[i].second;
    }
    cin >> s >> t;
    s--;
    t--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i].push_back({pow(input[i].first - input[j].first, 2) + pow(input[i].second - input[j].second, 2), j});
            }
        }
    }
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