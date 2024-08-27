#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }
    vector<int> s1(a.size());
    vector<int> s2(b.size());
    for (int i = 0; i < a.size(); i++) {
        s1[i] = a[i] - 'a';
        s2[i] = b[i] - 'a';
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < a.size(); i++) {
        if (s1[i] != s2[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}