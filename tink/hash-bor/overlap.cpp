//
// Created by smetanka on 26.04.24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string p, t;
    cin >> p >> t;

    vector<size_t> ans;
    size_t l_p = p.length(), l_t = t.length();
    int sovp = 0;


    for (size_t i = 0; i < l_p; i++) {
        if (t[i] == p[i])   sovp++;
    }
    if (sovp == l_p - 1 || sovp == l_p)    ans.push_back(1);

    for (size_t i = l_p; i < l_t; i++) {
        if (t[i - l_p] == p[i % l_p])    sovp--;
        if (t[i] == p[i % l_p]) sovp++;
        if (sovp == l_p - 1 || sovp == l_p)    ans.push_back(i - l_p + 2);
    }

    cout << ans.size() << "\n";
    for (size_t a : ans)   cout << a << " ";
}