//
// Created by mmura on 19.07.2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i].second >> mas[i].first;
    }
    sort(mas.begin(), mas.end());
    int count = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (mas[i].second > last) {
            last = mas[i].first;
            count++;
        }
    }
    cout << count;
}