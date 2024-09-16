#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b, saved = 0, cur = 0;
    string command;
    cin >> n >> b;

    while (n--) {
        cin >> command;
        if (command == "drink") {
            cur += b;
        } else if (command == "cast") {
            cur--;
        } else if (command == "save") {
            saved = cur;
        } else {
            cur = saved;
        }
        cout << cur << "\n";
    }

    return 0;
}