#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> mas(n);
    vector<int> ansl(n);
    vector<int> ansr(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= mas[i]) {
            st.pop();
        }
        if (st.empty()) {
            ansl[i] = 0;
        } else {
            ansl[i] = st.top();
        }
        st.push(mas[i]);
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= mas[i]) {
            s.pop();
        }
        if (s.empty()) {
            ansr[i] = 0;
        } else {
            ansr[i] = s.top();
        }
        s.push(mas[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ansl[i] << " " << ansr[i] << "\n";
    }
    return 0;
}