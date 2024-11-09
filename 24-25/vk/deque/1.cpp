#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cur;
    cin >> n;
    stack<int> st;
    while(n--) {
        cin >> cur;
        if (cur % 2 == 0) {
            st.push(cur);
        }
    }

    cout << st.top();
    
    return 0;
}