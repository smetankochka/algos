#include <vector>
#include <iostream>
#include <deque>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &prev, int v, int parent) {
    prev[v] = parent;
    for (int u : graph[v]) {
        if (prev[u] == -1) {
            dfs(graph, prev, u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cur;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        cin >> cur;
        cur--;
        graph[cur].push_back(i);
        graph[i].push_back(cur);
    }
    vector<int> prev(n, -1);
    dfs(graph, prev, 0, -2);
    cur = n - 1;
    deque<int> ans;
    while (cur != 0) {
        ans.push_front(cur + 1);
        cur = prev[cur];
    }
    cout << 1 << " ";
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    return 0;
}