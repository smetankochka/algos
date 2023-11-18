#include <iostream>
#include <vector>
#include <algorithm>
bool compare(const std::string& a, const std::string& b) {
    return a + b > b + a;
}
std::string getMaxNumber(std::vector<std::string>& numbers) {
    std::sort(numbers.begin(), numbers.end(), compare);
    std::string result;
    for (const auto& num : numbers) {
        result += num;
    }
    return result;
}
int main() {
    std::vector<std::string> numbers;
    std::string input;
    while (std::cin >> input) {
        numbers.push_back(input);
    }
    std::cout << getMaxNumber(numbers) << std::endl;
    return 0;
}