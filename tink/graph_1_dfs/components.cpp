#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, int &comp) {
    visited[v] = comp;
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (!visited[to]) {
            dfs(to, visited, graph, comp);
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> visited(n, 0);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, visited, graph, components);
        }
    }
    cout << components << "\n";
    vector<set<int>> components_set(components);
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            components_set[visited[i] - 1].insert(i + 1);
        }
    }
    for (int i = 0; i < components; i++) {
        cout << components_set[i].size() << "\n";
        for (int cur : components_set[i]) {
            cout << cur << " ";
        }
        cout << "\n";
    }
    return 0;
}
