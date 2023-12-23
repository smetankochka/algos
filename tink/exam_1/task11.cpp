#include <iostream>
#include <vector>

using namespace std;

struct trio {
    int zn;
    int loc;
    int gl;
};

void bin_search(vector<trio>& row, int p) {
    if (p <= row[0].gl) {
        cout << p - 1 << " ";
        return;
    }
    if (p > row.back().gl) {
        cout << row.back().zn + p - row.back().gl << " ";
        return;
    }
    int left = 0, right = row.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (row[mid].gl < p) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << row[left - 1].zn + p - row[left - 1].gl << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, p;
    cin >> n >> q;
    vector<trio> row(n);
    cin >> row[0].zn;
    row[0].loc = row[0].zn;
    row[0].gl = row[0].loc;
    for (int i = 1; i < n; i++) {
        cin >> row[i].zn;
        row[i].loc = row[i].zn - row[i - 1].zn - 1;
        row[i].gl = row[i].loc + row[i - 1].gl;
    }
    while (q--) {
        cin >> p;
        bin_search(row, p);
    }
    return 0;
}
