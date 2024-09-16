#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string rule, com;
    int k;
    cin >> com >> rule >> k;

    int uniq = 0, need = rule.size(), n = com.size(), cur_len = 0;
    int ansr = n;

    vector<bool> rules(26, false);
    for (char c : rule) {
        rules[c - 'a'] = true;
    }

    vector<int> counter(26, 0);

    for (int i = n - 1; i >= 0; i--) {
        if (!rules[com[i] - 'a']) {
            uniq = 0;
            ansr = i;
            fill(counter.begin(), counter.end(), 0);
            cur_len = 0;
            continue;
        }
        if (cur_len == k) {
            counter[com[i + cur_len] - 'a']--;
            if (rules[com[i + cur_len] - 'a'] && counter[com[i + cur_len] - 'a'] == 0) {
                uniq--;
            }
            cur_len--;
        }
        cur_len++;
        if (counter[com[i] - 'a'] == 0) {
            uniq++;
        }
        counter[com[i] - 'a']++;
        if (uniq == need) {
            for (int j = i; j < ansr; j++) {
                cout << com[j];
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}