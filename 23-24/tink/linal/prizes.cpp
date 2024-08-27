#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n + 1);
    std::vector<long long> s(n + 1, 0);
    std::vector<long long> pref(n + 1, 0);
    std::vector<long long> suff(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int i = k; i <= n; i++) {
        pref[i] = std::max(pref[i - 1], s[i] - s[i - k]);
    }

    for (int i = n - k + 1; i >= 1; i--) {
        suff[i] = std::max(suff[i + 1], s[i + k - 1] - s[i - 1]);
    }

    long long best = 2e18;
    for (int i = 1; i <= n - k + 1; i++) {
        best = std::min(best, std::max(pref[i - 1], suff[i + k]));
    }

    std::cout << best << std::endl;

    return 0;
}