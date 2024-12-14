#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> g;
vector<int> dist;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m, s, u, v, l;
    cin >> n >> m >> s;
    g.resize(n);
    dist.resize(n, 1e9);
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> l;
        g[v - 1].push_back(make_pair(l, u - 1));
    }
    dist[s - 1] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s - 1));
    while(!q.empty()) {
        v = q.top().second;
        l = -1 * q.top().first;
        q.pop();
        if (l > dist[v]){
            continue;
        }
        for (pair<int, int> p : g[v]) {
            if (dist[v] + p.first < dist[p.second]) {
                dist[p.second] = dist[v] + p.first;
                q.push(make_pair(-1 * dist[p.second], p.second));
            }
        }
    }
    for (int l : dist) {
        if (l == 1e9) {
            cout << -1 << " ";
        } else {
            cout << l << " ";
        }
    }
    return 0;
}