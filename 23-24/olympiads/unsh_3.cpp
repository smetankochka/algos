#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<string> surnames(n);
    vector<int> birthYears(n);
    vector<int> goalsScored(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> surnames[i] >> birthYears[i] >> goalsScored[i];
    }
    int maxGoals = 0;
    for (int goals : goalsScored) {
        maxGoals = max(maxGoals, goals);
    }
    for (int i = 0; i < n; ++i) {
        if (goalsScored[i] == maxGoals) {
            cout << names[i] << " " << surnames[i] << "\n";
        }
    }
    return 0;
}
