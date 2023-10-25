#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minfunc(int a, int b, int c, int d) {
    int ans = 1e9;
    if (a < ans) {
        ans = a;
    }
    if (b < ans) {
        ans = b;
    }
    if (c < ans) {
        ans = c;
    }
    if (d < ans) {
        ans = d;
    }
    return ans;
}
int maxfunc(int a, int b, int c, int d) {
    int ans = 0;
    if (a > ans) {
        ans = a;
    }
    if (b > ans) {
        ans = b;
    }
    if (c > ans) {
        ans = c;
    }
    if (d > ans) {
        ans = d;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> thing(4);
    vector<int> num(4);
    for (int i = 0; i < 4; ++i) {
        cin >> num[i];
        for (int j = 0; j < num[i]; j++) {
            int aj;
            cin >> aj;
            thing[i].push_back(aj);
        }
        sort(thing[i].begin(), thing[i].end());
    }
    int first = 0, second = 0, third = 0, fourth = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    int maxr = 1000000000;
    while (first < num[0] && second < num[1] && third < num[2] && fourth < num[3]) {
        int minm = minfunc(thing[0][first], thing[1][second], thing[2][third], thing[3][fourth]);
        int maxm = maxfunc(thing[0][first], thing[1][second], thing[2][third], thing[3][fourth]);
        int maxrcur = maxm - minm;
        if (maxrcur < maxr) {
            maxr = maxrcur;
            a1 = thing[0][first];
            a2 = thing[1][second];
            a3 = thing[2][third];
            a4 = thing[3][fourth];
        }
        while (first < num[0] && minm == thing[0][first]) {
            first++;
        }
        while (second < num[1] && minm == thing[1][second]) {
            second++;
        }
        while (third < num[2] && minm == thing[2][third]) {
            third++;
        }
        while (fourth < num[3] && minm == thing[3][fourth]) {
            fourth++;
        }
    }
    cout << a1 << " " << a2 << " " << a3 << " " << a4;
    return 0;
}
