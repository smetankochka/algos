#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cur, count = 0;
    vector<int> mas;
    cin >> n;
    while (n--) {
        cin >> cur;
        if (cur == 0) {
            count++;
        } else {
            mas.push_back(cur);
        }
    }

    for (int elem : mas) {
        cout << elem << " ";
    }
    for (int i = 0; i < count; i++) {
        cout << 0 << " ";
    }
    return 0;
}