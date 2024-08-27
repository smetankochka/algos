//
// Created by mmura on 08.06.2024.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int troom, tcond;
    string mode;
    cin >> troom >> tcond >> mode;
    if (mode == "heat"){
        if (troom < tcond) {
            cout << tcond;
        } else {
            cout << troom;
        }
    } else if (mode == "freeze") {
        if (troom > tcond) {
            cout << tcond;
        } else {
            cout << troom;
        }
    } else if (mode == "auto") {
        cout << tcond;
    } else {
        cout << troom;
    }
    return 0;
}