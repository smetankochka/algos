#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

pair<ll, int> maxs(const pair<ll, int> &a, const pair<ll, int> &b) {
    pair<ll, int> ans;
    if (a.first > b.first) {
        ans.first = a.first;
        ans.second = a.second;
    } else {
        ans.first = b.first;
        ans.second = b.second;
    }
    return ans;
}

struct segtree {
    int n;
    vector<pair<ll, int>> st;

    void build(int v, int l, int r, const vector<ll> &a) {
        if (l == r) {
            st[v].first = a[l];
            st[v].second = l;
            return;
        }
        int tmp = (l + r) / 2;
        build(v * 2, l, tmp, a);
        build(v * 2 + 1, tmp + 1, r, a);
        if (st[v * 2].first > st[v * 2 + 1].first) {
            st[v].first = st[v * 2].first;
            st[v].second = st[v * 2].second;
        } else {
            st[v].first = st[v * 2 + 1].first;
            st[v].second = st[v * 2 + 1].second;
        }
    }

    pair<ll, int> maximum(int v, int nl, int nr, int l, int r) {
        if (l > r) {
            return make_pair(-2e9, 0);
        }
        if (l == nl && r == nr) {
            return st[v];
        }
        int tmp = (nl + nr) / 2;
        return maxs(maximum(v * 2, nl, tmp, l, min(r, tmp)), maximum(v * 2 + 1, tmp + 1, nr, max(l, tmp + 1), r));
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
    int n, k, l, r;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    segtree s = segtree(a);
    cin >> k;
    while (k--) {
        cin >> l >> r;
        cout << s.maximum(1, 0, n - 1, l - 1, r - 1).second + 1<< "\n";
    }
    return 0;
}