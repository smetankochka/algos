#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int t = 1;
vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<int> rebra;

void dfs(int v) {
    used[v] = false;
    for (pair<int, int> u : g[v]) {
        if (rebra[u.second] == -1) {
            rebra[u.second] = t;
            t++;
            if (used[u.first]) {
                dfs(u.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, count = 0, index = 0, ai, bi;
    cin >> n >> m;
    used.resize(n, true);
    g.resize(n);
    rebra.resize(m, -1);
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi;
        g[ai - 1].push_back(make_pair(bi - 1, i));
        g[bi - 1].push_back(make_pair(ai - 1, i));
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            count++;
            index = i;
        }
    }
    if (count > 1) {
        cout << -1;
        return 0;
    }
    dfs(index);
    for (int i = 0; i < m; i++) {
        cout << rebra[i] << "\n";
    }
    return 0;
}