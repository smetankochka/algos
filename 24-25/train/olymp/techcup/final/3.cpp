#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(20);
    vector<bool> mas(n + 1, true);
    mas[0] = false;
    int count = n, cur = 0, chet;
    while (count > 0) {
        chet = 0;
        for (int i = 1; i <= n; i++) {
            if (mas[i]) {
                if (chet == 0) {
                    ans[cur].push_back(i);
                    mas[i] = false;
                    count--;
                    chet = 1;
                } else {
                    chet = 0;
                }
            }
        }
        cur++;
    }
    cout << cur << "\n";
    for (int i = 0; i < cur; i++) {
        cout << ans[i].size() << "\n";
        for (int c : ans[i]) {
            cout << c << " ";
        }
        cout << "\n";
    }
    return 0;
}
