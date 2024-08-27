#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &length, int v, int l) {
    visited[v] = true;
    length[v] = l;
    l++;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(graph, visited, length, u, l);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, start, a, b, maxl = -1;
    cin >> n >> start;
    start--;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n, false);
    vector<int> length(n, -1);
    vector<int> ans;
    dfs(graph, visited, length, start, 0);
    for (int i = 0; i < n; i++) {
        if (length[i] > maxl) { 
            maxl = length[i];
            ans.clear();
            ans.push_back(i + 1);
        } else if (length[i] == maxl) {
            ans.push_back(i + 1);
        }
    }
    for (int elem : ans) { 
        cout << elem << " ";
    }
    return 0;
}