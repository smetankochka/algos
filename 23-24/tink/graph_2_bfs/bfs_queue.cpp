#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, start, a, b, v;
    cin >> n >> m >> start;
    vector<vector<int>> g(n);
    vector<int> dist(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    queue<int> q;
    q.push(start - 1);
    dist[start - 1] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (dist[u] == -1) {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    for (auto x : dist) {
        cout << x << " ";
    }
    return 0;
}