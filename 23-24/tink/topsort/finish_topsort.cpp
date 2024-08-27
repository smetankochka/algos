//
// Created by smetanka on 09.03.24.
//
//
// Created by smetanka on 09.03.24.
//
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

ll bfs(int v, vector<vector<int>>& g, vector<int>& ts, vector<int>& ans, vector<bool>& used) {
    ll fsh = ts[v];
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            fsh += bfs(u, g, ts, ans, used);
        }
    }
    ans.push_back(v + 1);
    return fsh;
}

int main() {
    int n, m;
    cin >> n >> m;

}