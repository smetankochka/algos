#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long sumOfMinimums(const vector<int> &arr) {
    stack<int> s;
    int n = arr.size();
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            int tp = s.top();
            s.pop();
            int left = tp - (s.empty() ? -1 : s.top());
            int right = i - tp;
            result += (long long) arr[tp] * left * right;
        }
        s.push(i);
    }
    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int left = tp - (s.empty() ? -1 : s.top());
        int right = n - tp;
        result += (long long) arr[tp] * left * right;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << sumOfMinimums(array);
    return 0;
}
