#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int v) {
    if (visited[v]) {
        
    }
}

int main() {
    int n, m, v, u;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        graph[v - 1].push_back(u - 1);
    }
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
    return 0;
}