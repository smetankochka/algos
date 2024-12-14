#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> initial_assignment(n);
        for (int i = 0; i < n; ++i) {
            cin >> initial_assignment[i];
            initial_assignment[i]--; 
        }

        int m;
        cin >> m;

        vector<int> bad_kids(m);
        for (int i = 0; i < m; ++i) {
            cin >> bad_kids[i];
            bad_kids[i]--;
        }

        vector<int> good_kids;
        for (int i = 0; i < n; ++i) {
            bool is_bad = false;
            for (int j = 0; j < m; ++j) {
                if (i == bad_kids[j]) {
                    is_bad = true;
                    break;
                }
            }
            if (!is_bad) {
                good_kids.push_back(i);
            }
        }

        vector<int> final_assignment = initial_assignment;
        vector<bool> used(n, false);

        for (int i = 0; i < n; ++i) {
            bool is_bad = false;
            for (int j = 0; j < m; ++j) {
                if (i == bad_kids[j]) {
                    is_bad = true;
                    break;
                }
            }

            if (is_bad) {
                bool found = false;
                for (int j = 0; j < n; ++j) {
                    bool is_bad_recipient = false;
                    for (int k = 0; k < m; ++k) {
                        if (j == bad_kids[k]) {
                            is_bad_recipient = true;
                            break;
                        }
                    }
                    if (is_bad_recipient && final_assignment[i] != j && !used[j]) {
                        final_assignment[i] = j;
                        used[j] = true;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    for(int j=0; j<n; ++j){
                        bool is_bad_recipient = false;
                        for (int k = 0; k < m; ++k) {
                            if (j == bad_kids[k]) {
                                is_bad_recipient = true;
                                break;
                            }
                        }
                        if(is_bad_recipient && !used[j]){
                            final_assignment[i] = j;
                            used[j] = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << final_assignment[i] + 1 << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
