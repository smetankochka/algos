#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    bool n = 0, w = 0, s = 0, e = 0;

    for (auto elem : str) {
        if (elem == 'W') {
            w = true;
        } else if (elem == 'N') {
            n = true;
        } else if (elem == 'S') {
            s = true;
        } else {
            e = true;
        }
    }

    if (w == e && s == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}