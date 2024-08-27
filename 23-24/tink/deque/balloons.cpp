#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    deque<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int ci;
        cin >> ci;
        if (st.empty()) {
            st.push_back(make_pair(ci, 1));
            continue;
        }
        if (st.back().first == ci) {
            int count_equal = st.back().second + 1;
            st.push_back(make_pair(ci, count_equal));
            continue;
        }
        if (st.back().second >= 3) {
            count += st.back().second;
            int count_equal = st.back().second;
            while (count_equal--) {
                st.pop_back();
            }
        }
        if (st.empty()) {
            st.push_back(make_pair(ci, 1));
            continue;
        }
        if (st.back().first == ci) {
            int count_equal = st.back().second + 1;
            st.push_back(make_pair(ci, count_equal));
            continue;
        }
        st.push_back(make_pair(ci, 1));
    }
    if (st.back().second >= 3) {
        count += st.back().second;
        int count_equal = st.back().second;
        while (count_equal--) {
            st.pop_back();
        }
    }
    cout << count;
    return 0;
}
