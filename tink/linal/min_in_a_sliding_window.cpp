#include <iostream>
#include <deque>
using namespace std;
void append(deque<pair<int, int>> &dq, int f, int s) {
    while (!dq.empty() && dq.back().first >= f) {
        dq.pop_back();
    }
    dq.push_back(make_pair(f, s));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, f;
    cin >> n >> k;
    deque<pair<int, int>> dq;
    for (int i = 0; i < k; i++) {
        cin >> f;
        append(dq, f, i);
    }
    cout << dq.front().first << " ";
    for (int i = k; i < n; i++) {
        if (i - k == dq.front().second) {dq.pop_front();}
        cin >> f;
        append(dq, f, i);
        cout << dq.front().first << " ";
    }
}
