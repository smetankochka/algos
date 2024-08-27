#include <iostream>
#include <string>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = s.size(), i = -1;
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top() == ')' || st.top() == '}' || st.top() == ']') {
            st.push(s[i]);
            continue;
        }
        if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    if (st.empty()) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
