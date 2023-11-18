#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> num(10e8 + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> m;
        num[10e4 + m]++;
    }
    for (int i = 0; i <= 10e8; i++) {
        for (int j = 0; j < num[i]; j++) {
            cout << i - 10e4 << " ";
        }
    }
}