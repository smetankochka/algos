#include <iostream>
#include <deque>
using namespace std;
const int N = 5e5 + 5;
long long l[N];
long long r[N];
long long a[N];
long long b[N];
struct A {
    long long v, s, cnt, idx;
};
deque<A> dq;
int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dq.push_front({0, 0, 0, 0});
    for (long long i = 1; i <= n; i++) {
        long long s = a[i], cnt = 1;
        while (!dq.empty() && a[i] < dq.back().v) {
            s += dq.back().s;
            cnt += dq.back().cnt;
            dq.pop_back();
        }
        l[i] = s - (cnt * a[i]) + l[dq.back().idx];
        dq.push_back({a[i], s, cnt, i});
    }
    while (!dq.empty()) {
        dq.pop_back();
    }
    dq.push_front({0, 0, 0, 0});
    for (long long i = n; i >= 1; i--) {
        long long s = a[i], cnt = 1;
        while (!dq.empty() && a[i] < dq.back().v) {
            s += dq.back().s;
            cnt += dq.back().cnt;
            dq.pop_back();
        }
        r[i] = s - (cnt * a[i]) + r[dq.back().idx];
        dq.push_back({a[i], s, cnt, i});
    }
    long long mn = 1e15, id;
    for (long long i = 1; i <= n; i++) {
        if (l[i] + r[i] < mn) {
            id = i, mn = l[i] + r[i];
        }
    }
    for (long long i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    for (long long i = id - 1; i >= 1; i--) {
        if (b[i] > b[i + 1]) {
            b[i] = b[i + 1];
        }
    }
    for (long long i = id + 1; i <= n; i++) {
        if (b[i] > b[i - 1]) {
            b[i] = b[i - 1];
        }
    }
    for (long long i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}
