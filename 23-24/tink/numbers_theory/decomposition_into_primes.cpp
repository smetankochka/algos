//
// Created by smetanka on 18.12.23.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void primers(int n, vector<pair<int, int>>& ans) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            ans.push_back(make_pair(i, count));
        }
    }
    if (n > 1) {
        ans.push_back(make_pair(n, 1));
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    primers(n, ans);
    string res = "";
    res += to_string(ans[0].first);
    if (ans[0].second != 1) {res += "^" + to_string(ans[0].second);}
    for (int i = 1; i < ans.size(); i++) {
        res += "*";
        res += to_string(ans[i].first);
        if (ans[i].second != 1) {res += "^" + to_string(ans[i].second);}
    }
    cout << res;
}