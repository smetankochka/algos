#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, N;
    cin >> t >> N;
    stack<int> pancakes;
    for (int i = 0; i < t; i++) {
        int event;
        cin >> event;
        if (event == 1) {
            int radius;
            cin >> radius;
            if (pancakes.empty()) {
                pancakes.push(radius);
            } else {
                pancakes.push(min(pancakes.top(), radius));
            }
        } else if (event == 2) {
            pancakes.pop();
        } else if (event == 3) {
            cout << pancakes.top() << "\n";
        }
    }
    return 0;
}
