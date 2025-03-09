#include <iostream>
#include <vector>
using namespace std;
vector<int> mas;
struct segtree {
    int left, right;
    int sum = 0; // сумма на текущем отрезке
    segtree *l = 0, *r = 0;

    segtree (int _left, int _right) {
        left = _left;
        right = _right;
        if (left + 1 == right) {
            sum += mas[left];
        } else {
            int tmp = (left + right) / 2;
            l = new segtree(left, tmp);
            r = new segtree(tmp, right);
            sum = l->sum + r->sum;
        }
    }

    int get_sum (int l_q, int r_q) {
        if (left >= l_q && right <= r_q) {
            return sum;
        }
        if (max(left, l_q) >= min(right, r_q)) {
            return 0;
        }
        return l->get_sum(l_q, r_q) + r->get_sum(l_q, r_q);
    }

    void update(int k, int x) {
        sum += x;
        if (l) {
            if (k < l->right) {
                l->update(k, x);
            } else {
                r->update(k, x);
            }
        }
    }

};


int main() {
    int n, k;
    cin >> n >> k;
    mas.resize(n, 0);
    segtree *segment = new segtree(0, n);
    char c;
    int f, s;
    while(k--) {
        cin >> c >> f >> s;
        if (c == 'A') {
            segment->update(f - 1, s);
        } else {
            cout << segment->get_sum(f - 1, s) << "\n";
        }
    }
    return 0;
}