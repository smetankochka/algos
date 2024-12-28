#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> mas(n + m + 1);
    mas[0].first = -1;
    mas[0].second = 0;
    for(int i = 1; i <= n; i++) {
        cin >> mas[i].first;
        mas[i].second = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> mas[n + i + 1].second >>  mas[n + i + 1].first;
    }
    sort(mas.begin(), mas.end());
    for (int i = 1; i < n + m + 1; i++) {
        mas[i].second += mas[i - 1].second;
    }
    int left = 1, right = n + m + 1, mid;
    while (right > left + 1) {  
        mid = (left + right) / 2;
        if (mas[mid].second < k) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << mas[right].first;
    return 0;
}