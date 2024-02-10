#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct edge {
    int to, w;
};

int main() {
    int n, m, s, a, b, v, w;
    cin >> n >> m >> s;
    s--;
    vector<int> dist(n, -1);
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        g[a - 1].push_back({b - 1, w});
        g[b - 1].push_back({a - 1, w});
    }
    deque<int> q;
    q.push_back(s);
    dist[s] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop_front();
        for (auto [u, w] : g[v]) {
            if (dist[u] == -1 || dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                if (w == 0) {
                    q.push_front(u);
                } else {
                    q.push_back(u);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}