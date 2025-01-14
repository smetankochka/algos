#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int ans = mas[0];
    int ans_l = 0, ans_r = 0;
    int sum = 0, cur_sum;
    int min_sum = 0;
    int min_pos = -1;
    for (int r = 0; r < n; r++) {
        sum += mas[r];
        cur_sum = sum - min_sum;
        if (cur_sum > ans) {
            ans = cur_sum;
            ans_l = min_pos + 1;
            ans_r = r;
        }
        if (sum < min_sum) {
            min_sum = sum;
            min_pos = r;
        }
    }
    
    cout << ans_l + 1 << " " << ans_r + 1 << " " << ans;


    return 0;
}