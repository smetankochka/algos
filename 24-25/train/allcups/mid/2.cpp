#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<vector<int>> g2;
vector<bool> used;
vector<int> order;


void topsort(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            topsort(u);
        }
    }
    order.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    used.resize(n, false);
    vector<ll> length(n, 0);
    vector<ll> count_path(n, 0);
    vector<ll> length2(n, 0);
    vector<ll> count_path2(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g2[b - 1].push_back(a - 1);
    }
    topsort(0);
    count_path[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        for (int u : g[order[i]]) {
            length[order[i]] += length[u] + count_path[u];
            count_path[order[i]] += count_path[u];
        }
    }
    count_path2[0] = 1;
    for (int i = n - 2; i >= 0; i--) {
        for (int u : g2[order[i]]) {
            length2[order[i]] += length2[u] + count_path2[u];
            count_path2[order[i]] += count_path2[u];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << length[i] * count_path2[i] + length2[i] * count_path[i] << "\n";
    }

    return 0;
}