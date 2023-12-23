#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<pair<int, int>> details;  // Вектор для хранения деталей
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int cost, quality;
            cin >> cost >> quality;
            details.push_back({cost, quality});
        }
    }

    // Динамическое программирование для нахождения оптимального решения
    const int INF = 1e9 + 7;
    vector<int> dp(b + 1, -INF);
    dp[0] = 0;  // Базовый случай: 0 качество при 0 бюджете
    for (int i = 0; i < n; i++) {
        for (int j = b; j >= 0; j--) {
            if (j - details[i].first >= 0) {
                dp[j] = max(dp[j], min(dp[j - details[i].first], details[i].second));
            }
        }
    }

    if (dp[b] > 0) {
        cout << dp[b] << endl;  // Выводим качество собранного пульта
    } else {
        cout << -1 << endl;  // Если не удалось собрать пульт, выводим -1
    }

    return 0;
}
