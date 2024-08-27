#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int> &x, const pair<int, int> &y) {
    if (x.second > y.second) {
        return true;
    }
    if (x.second == y.second) {
        return x.first < y.first;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> mas(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mas[i] = make_pair(a, b);
    }
    sort(mas.begin(), mas.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << mas[i].first << " " << mas[i].second << "\n";
    }
}
