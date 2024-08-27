#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> mas(n);
    vector<ll> ans_left(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    stack<ll> st_left;
    st_left.push(0);
    ans_left[0] = -1;
    for (int i = 1; i < n; i++) {
        while (!st_left.empty() && mas[st_left.top()] >= mas[i]) {
            st_left.pop();
        }
        if (!st_left.empty()) {
            ans_left[i] = st_left.top();
        } else {
            ans_left[i] = -1;
        }
        st_left.push(i);
    }
    stack<ll> st_right;
    vector<ll> ans_right(n);
    st_right.push(n - 1);
    ans_right[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        while (!st_right.empty() && mas[st_right.top()] >= mas[i]) {
            st_right.pop();
        }
        if (!st_right.empty()) {
            ans_right[i] = st_right.top();
        } else {
            ans_right[i] = n;
        }
        st_right.push(i);
    }
    ll max_s = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] * (abs(ans_right[i] - ans_left[i] - 1)) > max_s) {
            max_s = mas[i] * (ans_right[i] - ans_left[i] - 1);
        }
    }
    cout << max_s;
}