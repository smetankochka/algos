#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct segtree {
    int n;
    vector<ll> st;

    void build(int v, int l, int r, const vector<ll> &a) {
        if (l == r) {
            st[v] = a[l];
            return;
        }
        if (l < r) {
            int tmp = (l + r) / 2;
            build(v * 2, l, tmp, a);
            build(v * 2 + 1, tmp + 1, r, a);
            st[v] = __gcd(st[v * 2], st[v * 2 + 1]);
        }
    }

    ll gcd(int v, int nl, int nr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == nl && r == nr) {
            return st[v];
        }
        int tmp = (nl + nr) / 2;
        return __gcd(gcd(v * 2, nl, tmp, l, min(r, tmp)), gcd(v * 2 + 1, tmp + 1, nr, max(l, tmp + 1), r));
    }

    void update(int v, int l, int r, int pos, ll val) {
        if (l == r) {
            st[v] = val;
            return;
        }
        int tmp = (l + r) / 2;
        if (pos <= tmp) {
            update(v * 2, l, tmp, pos, val);
        } else {
            update(v * 2 + 1, tmp + 1, r, pos, val);
        }
        st[v] = __gcd(st[v * 2], st[v * 2 + 1]);
    }

    segtree(const vector<ll> &a) {
        n = a.size();
        st.resize(4 * n);
        build(1, 0, n - 1, a);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, r, pos;
    ll x;
    char ty;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    segtree s = segtree(a);
    cin >> k;
    while (k--) {
        cin >> ty;
        if (ty == 's') {
            cin >> l >> r;
            cout << s.gcd(1, 0, n - 1, l - 1, r - 1) << " ";
        } else {
            cin >> pos >> x;
            s.update(1, 0, n - 1, pos - 1, x);
        }
    }
    return 0;
}
