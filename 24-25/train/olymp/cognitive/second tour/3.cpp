#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> weights;
vector<ll> subtree;
int cur = 0;
vector<vector<int>> g;

void dfs(int v, int prev) {
    subtree[v] = weights[v];
    for (int u : g[v]) {
        if (u != prev) {
            dfs(u, v);
            subtree[v] += subtree[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e, k, a, b;
    ll allik = 0;
    cin >> n >> e >> k;
    weights.resize(n);
    g.resize(n);
    subtree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        allik += weights[i];
    }
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            dfs(i, -1);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (abs(allik - subtree[i] * 2) <= k) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
