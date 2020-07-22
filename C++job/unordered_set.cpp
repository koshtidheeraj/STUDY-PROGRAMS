#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<std::string> set = {{"hello"},{"stop the thing"}};
    for (auto t : set) {
        std::cout << (t + "world") << std::endl;
    }
}