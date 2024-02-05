#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <stack>
using ll = long long;
using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k1, k2, w = 1, c1 = 0, c2 = 0;
    cin >> k1 >> k2;
    vector<pair<int, int>> ans;
    if (k1 > k2) {
        for (int i = 0; i < k2 + 1; i++) {
            ans.push_back(make_pair(w, w + 1));
            w++;
        }
        c2 = k2;
        c1 = k2 + 1;
        for (int i = 1; i <= k1 - c1; i++) {
            ans.push_back(make_pair(w - 1, w + i));
            if (i == k1 - c1) {
                w += i;
            }
        }
    } else {
        for (int i = 0; i <= k1 - 1; i++) {
            ans.push_back(make_pair(w, w + 1));
            w++;
        }
        int wcur = w;
        c1 = k1;
        c2 = max(k1 - 1, 0);
        bool flag = true;
        stack<int> st;
        while (k2 != c2) {
            c2++;
            if (flag) {
                w++;
                ans.push_back(make_pair(wcur, w));
                ans.push_back(make_pair(wcur - 1, w));
                w++;
                ans.push_back(make_pair(w - 1, w));
                flag = false;
            } else {
                ans.push_back(make_pair(wcur, w + 1));
                ans.push_back(make_pair(w - 1, w + 1));
                w += 2;
                ans.push_back(make_pair(w, w - 1));
                st.push(w);
            }
        }
        while (!st.empty()) {
            w++;
            ans.push_back(make_pair(w, st.top()));
            ans.push_back(make_pair(w, st.top() - 1));
            st.pop();
        }
    }
    cout << w << " " << ans.size() << "\n";
    for (pair<int, int> &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}