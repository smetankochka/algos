#include <iostream>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string>& words) {
    std::string result = "";
    if (words.size() == 0) {
        return result;
    }

    size_t minlen = 1e9;
    for (std::string x : words) {
        if (x.size() < minlen) {
            minlen = x.size();
        }
    }

    while (minlen--) {
        char cur = words[0][result.size()];
        bool net = false;
        for (size_t i = 1; i != words.size(); ++i) {
            if (words[i][result.size()] != cur) {
                net = true;
                break;
            }
        }
        if (net) {
            break;
        }
        result += cur;
    }

    return result;
}

int main() {
    std::vector<std::string> mas;
    mas.push_back("apple");
    mas.push_back("apricot");
    mas.push_back("application");
    std::cout << CommonPrefix(mas);
    return 0;
}