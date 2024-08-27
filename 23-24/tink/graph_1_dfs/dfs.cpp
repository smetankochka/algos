#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<bool>> &graph, vector<bool> &visited, int v, int &count) {
    visited[v] = true;
    count++;
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, i, count);
        }
    }
}

int main() {
    int n, s, count = 0;
    bool cur;
    cin >> n >> s;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cur;
            if (cur) g[i][j] = true;
        }
    }
    vector<bool> visited(n, false);
    dfs(g, visited, s - 1, count);
    cout << count;
    return 0;
}
