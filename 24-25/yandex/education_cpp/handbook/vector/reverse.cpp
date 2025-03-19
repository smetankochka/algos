#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans(n);
    for (int i = 0; i != n; ++i) {
        int cur;
        std::cin >> cur;
        ans[cur - 1] = i + 1;
    }
    for (int x : ans) {
        std::cout << x << " ";
    }
}