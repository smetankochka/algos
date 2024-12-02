#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>


using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, ui, vi, c, cur;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    for (int i = 0; i < k; i++) {
        cin >> ui >> vi >> c;
        graph[vi - 1].push_back(c);
        graph[ui - 1].push_back(c);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() > 2) {
            cur = 0;
            bool flag = true;
            for (int p : graph[i]) {
                if (cur == 0) {
                    cur = p;
                } else if (cur != p) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
    }



    cout << count << endl;
    return 0;
}
