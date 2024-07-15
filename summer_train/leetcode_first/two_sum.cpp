#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans(2);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums{3, 3};
    int target = 6;
    vector<int> a = twoSum(nums, target);
    cout << a[0] << " " << a[1] << "\n";
    return 0;
}