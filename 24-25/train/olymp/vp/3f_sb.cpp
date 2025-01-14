#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cur_x, cur_h;
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> cur_x >> cur_h;
        if (!st.empty() && abs(-cur_x + st.top().first) <= st.top().second - cur_h) {
            continue;
        }
        while (!st.empty() && abs(cur_x - st.top().first) <= cur_h - st.top().second) {
            st.pop();
        }
        st.push(make_pair(cur_x, cur_h));
    }
    cout << st.size();

    return 0;
}