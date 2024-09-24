#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
vector<int> ans;
vector<vector<int>> g;
vector<short int> used;

void topsort(int v) {
    used[v] = 1;

    for (int u : g[v]) {
        if (!used[u]) {
            topsort(u);
        } else if (used[u] == 1) {
            cout << -1;
            exit(0);
        }
    }

    ans.push_back(v + 1);
    used[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    while (m--) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            topsort(v);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int v : ans) {
        cout << v << " ";
    }

    return 0;
}
