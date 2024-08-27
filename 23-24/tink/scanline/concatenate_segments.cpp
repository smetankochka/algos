#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segment {
    int start;
    int end;
};

struct point {
    int place;
    bool status;
};

bool comp(point &a, point &b) {
    if (a.place == b.place) {
        return a.status > b.status;
    }
    return a.place < b.place;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<point> mas(2 * n);
    vector<segment> ans;
    for (int i = 0; i < n; i++) {
        cin >> mas[i * 2].place >> mas[i * 2 + 1].place;
        mas[i * 2].status = true;
        mas[i * 2 + 1].status = false;
    }
    sort(mas.begin(), mas.end(), comp);
    int ansstart = 0, count = 0;
    for (point p : mas) {
        if (p.status) {
            if (count == 0) {
                ansstart = p.place;
            }
            count++;
        } else {
            count--;
            if (count == 0) {
                ans.push_back({ansstart, p.place});
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.start << " " << p.end << "\n";
    }
}