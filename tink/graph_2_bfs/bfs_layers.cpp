#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, start, a, b;
    cin >> n >> m >> start;
    vector<vector<int>> g(n);
    vector<int> dist(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<vector<int>> layers(n);
    layers[0].push_back(start - 1);
    dist[start - 1] = 0;
    for (int i = 0; i < n; i++) {
        for (auto v : layers[i]) {
            for (auto u : g[v]) {
                if (dist[u] == -1) {
                    layers[i + 1].push_back(u);
                    dist[u] = i + 1;
                }
            }
        }
    }
    for (auto x : dist) {
        cout << x << " ";
    }
    return 0;
}