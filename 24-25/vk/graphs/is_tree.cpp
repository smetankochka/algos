#include <fstream>
#include <vector>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");


void dfs(int v, int parent, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (!visited[to]) {
            dfs(to, v, visited, graph);
        } else if (to != parent) {
            cout << "NO";
            exit(0);
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, graph);
            components++;
        }
    }

    if (m == n - 1 && components == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
