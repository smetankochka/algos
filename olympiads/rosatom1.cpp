#include <iostream>
using namespace std;

int f(int x, int y) {
    if (x == 0 || y == 0) return 1;
    if (x > y) return f(x - 1, y) + 2;
    return f(x, y - 1) + 1;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << f(x, y);
    return 0;
}