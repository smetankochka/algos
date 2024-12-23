#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rest(n);
    for (int i = 0; i < n; ++i) {
        cin >> rest[i];
    }

    sort(rest.begin(), rest.end());
    vector<int> valleys(rest.begin(), rest.begin() + n / 2);
    vector<int> peaks(rest.begin() + n / 2, rest.end());

    int matched = 0;
    auto peak_iter = peaks.begin();

    for (int valley : valleys) {
        bool found_peak = false;
        for ( ; peak_iter != peaks.end(); ++peak_iter) {
            if (*peak_iter > valley) {
                matched++;
                found_peak = true;
                break;
            }
        }
        if (!found_peak) break;
    }

    cout << (n / 2) - matched;

    return 0;
}

