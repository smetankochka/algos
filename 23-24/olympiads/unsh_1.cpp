#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string result = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int x = (i >= 0) ? (num1[i] - '0') : 0;
        int y = (j >= 0) ? (num2[j] - '0') : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;
        result.push_back('0' + sum);
        i--;
        j--;
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}
