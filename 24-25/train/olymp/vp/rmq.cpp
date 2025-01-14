#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int inf = 1000000000;
vector<int> mas;
vector<pair<int, int>> tree; // index, maximum 

void build(int cur, int left, int right) {
    if (left == right) {
        tree[cur].first = left;
        tree[cur].second = mas[left];
    } else {
        int mid = (left + right) / 2;
        build(cur * 2, left, mid);
        build(cur * 2 + 1, mid + 1, right);
        if (tree[cur * 2].second > tree[cur * 2 + 1].second) {
            tree[cur].second = tree[cur * 2].second;
            tree[cur].first = tree[cur * 2].first;
        } else {
            tree[cur].second = tree[cur * 2 + 1].second;
            tree[cur].first = tree[cur * 2 + 1].first;
        }
    }
}

pair<int, int> maximum (int cur, int left, int right, int q_left, int q_right) {
    if (q_left > q_right) {
        return make_pair(-inf, -inf);
    }
    if (q_left == left && q_right == right) {
        return make_pair(tree[cur].first, tree[cur].second);
    }
    int mid = (left + right) / 2;
    pair<int, int> res1 = maximum(cur * 2, left, mid, q_left, min(r, mid));
    pair<int, int> res2 = maximum(cur * 2 + 1, mid + 1, right, )
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    mas.resize(n);
    tree.resize(4 * n, make_pair(-inf, -inf));
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    build(1, 0, n - 1);


    return 0;
}