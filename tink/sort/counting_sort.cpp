#include <iostream>
#include <vector>
using namespace std;
void countingSort(vector<int>& arr) {
    const int MAX_VALUE = 10000;
    const int OFFSET = 10000;
    vector<int> count(2 * MAX_VALUE + 1, 0);
    for (int num : arr) {
        count[num + OFFSET]++;
    }
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = i - OFFSET;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    countingSort(elements);
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    return 0;
}
