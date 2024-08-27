#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int node, int color, const vector<vector<int>>& graph, vector<int>& group, vector<int>& visited) {
    visited[node] = 1;
    group[node] = color;

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            if (!dfs(neighbor, 1 - color, graph, group, visited))
                return false;
        } else if (group[neighbor] == color) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, cur1, cur2;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> cur1 >> cur2;
        graph[cur1].push_back(cur2);
        graph[cur2].push_back(cur1);
    }
    vector<int> visited(n + 1, 0);
    vector<int> group(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, 0, graph, group, visited)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
