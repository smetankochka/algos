#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<string, string>> sinonims(n);
    for (int i = 0; i < n; i++) {cin >> sinonims[i].second >> sinonims[i].first;}
    string find;
    cin >> find;
    for (int i = 0; i < n; i++) {
        if (find == sinonims[i].first) {
            cout << sinonims[i].second;
            return 0;
        }
        if (find == sinonims[i].second) {
            cout << sinonims[i].first;
            return 0;
        }
    }
}
