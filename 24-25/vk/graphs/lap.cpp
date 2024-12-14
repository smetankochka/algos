#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ai, cur;
    cin >> n;
    vector<int> mas;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        while (ai--) {
            cin >> cur;
            mas.push_back(cur);
        }
    }
    sort(mas.begin(), mas.end());
    
    return 0;
}