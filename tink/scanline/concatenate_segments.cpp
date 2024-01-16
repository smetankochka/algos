#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int start;
    int end;
};

bool comp(point &a, point &b) {
    return a.start <= b.start;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<point> mas(n);
    vector<point> ans;
    for (int i = 0; i < n; i++) {
        cin >> mas[i].start >> mas[i].end;
    }
    sort(mas.begin(), mas.end(), comp);
    int ansstart = mas[0].start, ansend = mas[0].end;
    for (int i = 1; i < n; i++) {
        if (mas[i].start > ansend) {
            ans.push_back(point{ansstart, ansend});
            ansstart = mas[i].start;
            ansend = mas[i].end;
        } else if (mas[i].end > ansend) {
            ansend = mas[i].end;
        }
    }
    ans.push_back(point{ansstart, ansend});
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.start << " " << p.end << "\n";
    }
}