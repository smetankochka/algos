#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> friends = {"LeshaMaren", "Danya", "Vasya", "Dima", "Jenya", "LeshaVasil", "Ilia", "Gosha"};
vector<vector<string>> allPermutations;
vector<vector<string>> requirements;

bool satisfiesRequirement(const vector<string> &permutation, const string &requirement) {
    auto pos1 = find(permutation.begin(), permutation.end(), requirement.substr(0, requirement.find(' ')));
    auto pos2 = find(permutation.begin(), permutation.end(), requirement.substr(requirement.rfind(' ') + 1));
    return requirement.find("before") != string::npos ? pos1 < pos2 : pos1 > pos2;
}

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string requirement;
        getline(cin, requirement);
        requirements.push_back({requirement});
    }
    sort(friends.begin(), friends.end());
    do {
        allPermutations.push_back(friends);
    } while (next_permutation(friends.begin(), friends.end()));
    for (const auto &p: allPermutations) {
        bool satisfiesAllRequirements = true;
        for (const auto &r: requirements) {
            if (!satisfiesRequirement(p, r[0])) {
                satisfiesAllRequirements = false;
                break;
            }
        }
        if (satisfiesAllRequirements) {
            for (const auto &friendName: p) {
                cout << friendName << " ";
            }
            break;
        }
    }
    return 0;
}
