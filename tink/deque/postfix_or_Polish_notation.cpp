#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    s += ' ';
    int uk = s.size() - 1;
    while (s[uk] == ' ') {
        uk--;
    }
    int i = 0;
    stack<int> st;
    while (i <= uk) {
        if (s[i] == '+' && s[i + 1] == ' ') {
            int sum = st.top();
            st.pop();
            sum += st.top();
            st.pop();
            st.push(sum);
            i++;
        } else if (s[i] == '-' && s[i + 1] == ' ') {
            int rasn = st.top();
            st.pop();
            rasn = st.top() - rasn;
            st.pop();
            st.push(rasn);
            i++;
        } else if (s[i] == '*' && s[i + 1] == ' ') {
            int multi = st.top();
            st.pop();
            multi *= st.top();
            st.pop();
            st.push(multi);
            i++;
        } else {
            int num = 0;
            bool flag = false;
            if (s[i] == '-') {
                flag = true;
                i++;
            }
            int c = 1;
            while (s[i] != ' ') {
                num += c * (s[i] - '0');
                c *= 10;
                i++;
            }
            if (flag) {
                num *= -1;
            }
            st.push(num);
        }
        i++;
    }
    cout << st.top();
    return 0;
}
