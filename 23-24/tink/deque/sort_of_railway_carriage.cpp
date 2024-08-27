#include <iostream>
#include <deque>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    deque<int> tupik;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    vector<pair<int, int>> ans;
    int ans_now = 1;
    int tupikpredsize = 0;
    int i = -1;
    while (i < n - 1) {
        do {
            i++;
            tupik.push_back(input[i]);
        } while (i < n && ans_now != input[i]);
        if (!tupik.empty()) {
            ans.push_back(make_pair(1, tupik.size() - tupikpredsize));
            int count = 1;
            tupik.pop_back();
            while (!tupik.empty() && tupik.back() - ans_now == 1) {
                ans_now++;
                count++;
                tupik.pop_back();
            }
            ans_now++;
            ans.push_back(make_pair(2, count));
        }
        tupikpredsize = tupik.size();
    }
    if (tupik.empty()) {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    } else {
         cout << 0;
    }
    return 0;
}
