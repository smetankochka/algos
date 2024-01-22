#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct point {
    int x;
    int y;
    bool start;
    int number;
};

bool comp(point a, point b) {
    if (a.x == b.x) {
        if (a.start && b.start) {
            return a.y > b.y;
        }
        return a.start > b.start;
    } 
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<point> mas(2 * n);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> mas[2 * i].x >> mas[2 * i + 1].x;
        mas[2 * i].y = mas[2 * i + 1].x;
        mas[2 * i + 1].y = mas[2 * i].x;
        mas[2 * i].start = true;
        mas[2 * i + 1].start = false;
        mas[2 * i].number = i + 1;
        mas[2 * i + 1].number = i + 1;
    }
    sort(mas.begin(), mas.end(), comp);
    set<pair<int, pair<int, int>>> opened;
    for (int i = 0; i < 2 * n; i++) {
        if (mas[i].start) {
            if (!opened.empty() && (*opened.rbegin()).first >= mas[i].y) {
                if (((*opened.rbegin()).first == mas[i].y) && (*opened.rbegin()).second.first == mas[i].x) {
                    ans[(*opened.rbegin()).second.second - 1] = mas[i].number;
                }
                ans[mas[i].number - 1] = (*opened.rbegin()).second.second;
            }
            opened.insert(make_pair(mas[i].y, make_pair(mas[i].x, mas[i].number)));
        } else {
            opened.erase(make_pair(mas[i].y, make_pair(mas[i].x, mas[i].number)));
        }
    }
    for (int a : ans) {
        cout << a << " ";
    }
    return 0;
}
