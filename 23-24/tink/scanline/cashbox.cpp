#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int time;
    bool status;
};

bool cmp(point a, point b) {
    if (a.time == b.time) {
        return a.status > b.status;
    }
    return a.time < b.time;
}

int main() {
    int n, h1, h2, m1, m2, s1, s2, t1, t2;
    cin >> n;
    vector<point> ev;
    for (int i = 0; i < n; i++) {
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        t1 = h1 * 3600 + m1 * 60 + s1;
        t2 = h2 * 3600 + m2 * 60 + s2;
        if (t1 == t2) {
            ev.push_back(point{86400, 0});
            ev.push_back(point{0, 1});
            continue;
        }
        ev.push_back(point{t1, 1});
        ev.push_back(point{t2, 0});
        if (t1 > t2) {
            ev.push_back(point{86400, 0});
            ev.push_back(point{0, 1});
        }
    }
    sort(ev.begin(), ev.end(), cmp);
    int count = 0, tmstart = 0, ans = 0;
    for (point p : ev) {
        if (count == n) {
            ans += p.time - tmstart;
        }
        if (p.status) {
            count++;
        } else {
            count--;
        }
        if (count == n) {
            tmstart = p.time;
        }
    }
    cout << ans;
    return 0;
}