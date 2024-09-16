#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <functional>

int main() {
    std::string s;
    std::cin >> s;

    std::set<size_t> unique_hashes;
    int n = s.length();
    unique_hashes.insert(std::hash<std::string>{}(s));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            std::string copy = s;
            std::string substring = s.substr(i, j - i + 1);
            std::reverse(substring.begin(), substring.end());
            copy.replace(i, j - i + 1, substring);
            unique_hashes.insert(std::hash<std::string>{}(copy));
        }
    }
    std::cout << unique_hashes.size() << std::endl;

    return 0;
}