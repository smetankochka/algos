#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
vector<vector<int>> g;
vector<int> comp;

void dfs(int v) {
    comp[v] = 1;
    for (int u : g[v]) {
        if (comp[u] == 0) {
            dfs(u);
        }
    }
}


int main() {
    int n, s;
    cin >> n >> s;
    g.resize(n);
    comp.resize(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (c == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    dfs(s-1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += comp[i];
    }
    cout << ans;
    return 0;
}