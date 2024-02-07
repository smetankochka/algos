#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ogran{
    bool s;
    int o1, o2;
};

struct offset{
    ogran ryad;
    ogran mesto;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, p, cur, si, ri, ci, q;
        cin >> n >> m >> k >> p;
        int count = k;
        vector<vector<pair<int, bool>>> mas(n, vector<pair<int, bool>> (m, make_pair(-1, false)));
        vector<offset> og(k);
        vector<bool> used(k, false);
        char ty;
        for (int i = 0; i < p; i++) {
            cin >> ty >> cur;
            if (ty == 'R') {
                cin >> og[cur - 1].ryad.o1 >> og[cur - 1].ryad.o2;
                og[cur - 1].ryad.o1--;
                og[cur - 1].ryad.o2--;
                og[cur - 1].ryad.s = true;
            } else {
                cin >> og[cur - 1].mesto.o1 >> og[cur - 1].mesto.o2;
                og[cur - 1].mesto.o1--;
                og[cur - 1].mesto.o2--;
                og[cur - 1].mesto.s = true;
            }
        }
        cin >> q;
        string trash;
        for (int i = 0; i < q; i++) {
            cin >> trash >> si >> ri >> ci;
            si--;
            ri--;
            ci--;
            if (!used[si] && mas[ri][ci].first == -1) {
                used[si] = true;
                mas[ri][ci].first = si;
                if (og[si].ryad.s && (og[si].ryad.o1 > ri || og[si].ryad.o2 < ri)) {
                     mas[ri][ci].second = true;
                } else if (og[si].mesto.s && (og[si].mesto.o1 > ci || og[si].mesto.o2 < ci)) {
                     mas[ri][ci].second = true;
                } else {
                    count--;
                }
            } else if (used[si]) {
                if (mas[ri][ci].second && ((og[si].ryad.s && (og[si].ryad.o1 > ri || og[si].ryad.o2 < ri)) || (og[si].mesto.s && (og[si].mesto.o1 > ci || og[si].mesto.o2 < ci)))) {
                    used[si] = true;
                    used[mas[ri][ci].first] = false;
                    mas[ri][ci].first = si;
                    count--;
                }
            }
        }
        cout << count << "\n";
    }
}
