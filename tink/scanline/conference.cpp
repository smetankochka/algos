#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

struct Talk {
    int start;
    int end;
};

bool compareTalks(const Talk& a, const Talk& b) {
    return a.start < b.start;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<Talk> talks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> talks[i].start >> talks[i].end;
    }

    std::sort(talks.begin(), talks.end(), compareTalks);

    std::multiset<int> endTimes;
    int maxTalks = 0;

    for (int i = 0; i < n; i++) {
        while (!endTimes.empty() && *endTimes.begin() <= talks[i].start) {
            endTimes.erase(endTimes.begin());
        }

        if (endTimes.size() < k) {
            endTimes.insert(talks[i].end);
            maxTalks = std::max(maxTalks, static_cast<int>(endTimes.size()));
        }
    }

    std::cout << maxTalks << std::endl;

    return 0;
}