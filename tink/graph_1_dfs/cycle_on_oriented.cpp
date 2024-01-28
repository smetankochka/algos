
#include <vector>
#include <iostream>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& state, int v) {
    state[v] = 1;
    for (int u : graph[v]) {
        if (state[u] == 0) {
            if (dfs(graph, state, u)) {
                return true;
            }
        } else if (state[u] == 1) {
            return true;
        }
    }
    state[v] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> v >> u;
        graph[v - 1].push_back(u - 1);
    }
    vector<int> state(n, 0);
    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && dfs(graph, state, i)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}