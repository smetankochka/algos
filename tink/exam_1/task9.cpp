#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Detail {
    int cost;
    int quality;
};

bool compareCost(const Detail& d1, const Detail& d2) {
    return d1.cost < d2.cost;
}

int main() {
    int n, b;
    cin >> n >> b;

    vector<Detail> details;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int cost, quality;
            cin >> cost >> quality;
            details.push_back({cost, quality});
        }
    }

    sort(details.begin(), details.end(), compareCost);

    int maxQuality = -1;
    int currCost = 0;
    for (const auto& detail : details) {
        currCost += detail.cost;
        if (currCost > b)
            break;
        maxQuality = max(maxQuality, detail.quality);
    }

    cout << maxQuality - 1;

    return 0;
}