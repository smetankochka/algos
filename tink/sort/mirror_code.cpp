#include <iostream>
#include <string>
#include <vector>
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
        if (mapa.contains(k)) {
            mapa[k]++;
        } else {
            mapa[k] = 1;
        }
    }
    string ans = "", mid = "";
    for (const auto& [letter, count] : products) {
        for (int i = 0; i < count / 2; i++) {ans.append(letter)}
        if (mid.size() == 0 && count % 2 == 1) {mid.append(letter);}
    }
    cout << ans << " " << mid << "\n";
}