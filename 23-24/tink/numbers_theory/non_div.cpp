#include <iostream>

using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; 
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

void solveEquation(int a, int b, int c) {
    int x, y;
    int d = extendedGCD(a, b, x, y);

    if (c % d == 0) {
        x *= (c / d);
        y *= (c / d);
        cout << d << " " << x << " " << y << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    solveEquation(a, b, c);

    return 0;
}
