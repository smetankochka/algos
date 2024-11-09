#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    
    sort(ls.rbegin(), ls.rend());

    int maxans = 0;

    for (int i = 0; i < n; i++) {
        int elem = ls[i];
        
        if (elem * 2 <= i + 1) {
            int left = elem;
            int right = ls[0];
            int ans = 0;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (i + 1 - elem * 2 >= mid - elem && ls[elem - 1] >= mid) {
                    left = mid + 1;
                    ans = mid;
                } else {
                    right = mid - 1;
                }
            }
            
            maxans = max(maxans, ans * elem);
        }
    }

    cout << maxans;

    return 0;
}