#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    bool cur;
    cin >> n >> m;
    vector<vector<int>> mas(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cur;
            if (!cur && i == 0) {
                mas[i][j] = 1;
            } else if (!cur) {
                mas[i][j] = mas[i - 1][j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        stack<pair<int, int>> st;
        
    }
}