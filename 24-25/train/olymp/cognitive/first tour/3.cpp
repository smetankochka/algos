#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, rate, ans, ansnew;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> pom(n);
        vector<pair<int, int>> pom1(n);
        for (int i =0; i < n; i++) {
            cin >> pom[i].first;
            pom[i].second = i;
        }
        sort(pom.begin(), pom.end(), comp);
        sort(pom1.begin(), pom1.end());
        bool flag = false;
        rate = 1, ans = 1;
        vector<pair<int, int>> rate_index(n + 1);
        rate_index[0].first = -1, rate_index[0].second = -1;
        for (int i = 0; i < n; i++) {
            if (rate < pom[i].first) {
                flag = true;
                break;
            }
            if (rate_index[i - rate + pom[i].first].first < ans || (rate_index[i - rate + pom[i].first].first == ans && rate_index[i - rate + pom[i].first].second < pom[i].second)) {
                rate_index[rate].first = ans, rate_index[rate].second = pom[i].second;
            } else if ((rate_index[i - rate + pom1[i].first].first < ans || (rate_index[i - rate + pom1[i].first].first == ans && rate_index[i - rate + pom1[i].first].second < pom1[i].second))){
                rate_index[rate].first = ans, rate_index[rate].second = pom1[i].second;
            }else{
                ans++;
                rate_index[rate].first = ans, rate_index[rate].second = max(pom[i].second, pom1[i].second);
            }
            rate++;
        }
        if (flag) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
        
    }
    
    return 0;
}