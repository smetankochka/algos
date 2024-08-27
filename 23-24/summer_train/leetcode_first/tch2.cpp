#include <iostream>

using namespace std;
using ll = long long;

int count = 0;

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    count++;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    int n = gcd(a, b);
    cout << count << "\n";
    return 0;
}