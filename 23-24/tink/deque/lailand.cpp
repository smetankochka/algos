#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> lapl(n);
    for (int i = 0; i < n; i++) {cin >> lapl[i];}
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && lapl[st.top()] > lapl[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; ++i) {cout << res[i] << " ";}
    return 0;
}
