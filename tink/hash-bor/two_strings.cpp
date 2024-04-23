//
// Created by smetanka on 23.04.24.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int q;
    cin >> s >> q;

    // считаем все степени p
    const int p = 31;
    vector<ll> p_pow(s.length());
    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }

    // считаем хеши для всех префиксов
    vector<ll> hashes(s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        hashes[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i)  hashes[i] += hashes[i - 1];
    }

    // обработка запросов
    int l1, l2, r1, r2;
    ll h1, h2;
    while (q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        l2--;
        r1--;
        r2--;

        h1 = hashes[r1];
        if (l1) h1 -= hashes[l1 - 1];
        h2 = hashes[r2];
        if (l2) h2 -= hashes[l2 - 1];

        if ((l1 < l2 && h1 * p_pow[l2 - l1] == h2) || (l2 < l1 && h2 * p_pow[l1 - l2] == h1) || (l1 == l2 && r1 == r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}