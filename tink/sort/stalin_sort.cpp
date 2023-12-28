#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, last = -1e9, tmp;
    cin >> n;
    vector<int> ans;
    while(n--) {
        cin >> tmp;
        if (tmp > last) {
            last = tmp;
            ans.push_back(tmp);
        }
    }
    for (int elem: ans) {
        cout << elem << " ";
    }
}