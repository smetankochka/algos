#include <iostream>
#include <vector>

using namespace std;

bool is_triangle(int a, int b, int c) {
  return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  if (is_triangle(a, b, c) && is_triangle(d, e, f)) {
    cout << 1 << endl;
    if (b == e && ((a == d && c == f) || (a == f && c == d))) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    cout << 0 << endl;
  }
  return 0;
}

