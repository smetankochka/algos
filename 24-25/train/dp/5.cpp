#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
vector<vector<int>> graph;
vector<int> components_mas;


void dfs(int v, int comp) {
    components_mas[comp - 1] += 1;
    visited[v] = comp;
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (!visited[to]) {
            dfs(to, comp);
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    visited.resize(n, 0);
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            components_mas.push_back(0);
            dfs(i, components);
        }
    }
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, cur;
    for (int i = 0; i < components; i++) {
        count4 += components_mas[i] / 4;
        cur = components_mas[i] - components_mas[i] / 4 * 4;
        if (cur == 3) {
            count3++;
        } else if(cur == 2) {
            count2++;
        } else if (cur == 1) {
            if (components_mas[i] / 4 > 0) {
                count4--;
                count3++;
                count2++;
            } else {
                count1++;
            }
        }
    }
    cout << count1 << "\n" << count2 << "\n" << count3 << "\n" << count4;
    return 0;
}
