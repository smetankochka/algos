#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    char k;
    cin >> n;
    map<char, int> mapa;
    while (n--) {
        cin >> k;
        if (mapa.count(k) > 0) {
            mapa[k]++;
        } else {
            mapa[k] = 1;
        }
    }
    string ans = "", mid = "";
    for (const auto& [letter, count] : mapa) {
        for (int i = 0; i < count / 2; i++) {ans += letter;}
        if (mid.size() == 0 && count % 2 == 1) {mid += letter;}
    }
    string ansfinish = ans;
    reverse(ansfinish.begin(), ansfinish.end());
    cout << ans + mid + ansfinish;
}