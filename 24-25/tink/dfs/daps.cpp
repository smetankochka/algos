#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, a, b, d, start;
vector<vector<pair<int, int>>> g;
vector<ll> rast;

void dfs(int v) {
    for (pair<int, int> p : g[v]) {
        if (rast[p.first] < rast[v] + p.second) {
            rast[p.first] = rast[v] + (ll)p.second;
            dfs(p.first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    rast.resize(n, -1);
    g.resize(n);
    while (m--) {
        cin >> a >> b >> d;
        g[a - 1].push_back(make_pair(b - 1, d));
    }

    cin >> start;
    start--;
    rast[start] = 0;
    dfs(start);
    for (ll r : rast) {
        cout << r << " ";
    }

    return 0;
}