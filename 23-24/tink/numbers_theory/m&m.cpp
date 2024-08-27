#include <iostream>

const long long MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    long long result = (3 % MOD * 2 % MOD * 2 % MOD);
    for (int i = 0; i < n - 1; ++i) {
        result = (result % MOD * 3 % MOD * 2 % MOD) % MOD;
    }

    result = (result - (3 % MOD * 2 % MOD * (2 % MOD * 2 % MOD) % MOD) % MOD + MOD) % MOD;

    std::cout << result << std::endl;

    return 0;
}
