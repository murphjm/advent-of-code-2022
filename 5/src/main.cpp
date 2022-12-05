#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    std::vector<std::string> in;

    while(std::getline(file, line) && line[1] != '1') {
        in.push_back(line);
    }

    std::vector<std::stack<char>> stacks(line.size() / 4 + 1);
    for (int i = in.size() - 1; i >= 0; i--) {
        for (unsigned long j = 0; j < stacks.size(); j ++) {
        const int k = j * 4 + 1;
        if (in[i][k] == ' ') continue;
        stacks[j].push(in[i][k]);
        }
    }

    std::getline(file, line);
    const std::regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
    while (std::getline(file, line)) {
        // if (line == "") break;
        std::smatch match;
        std::regex_match(line, match, pattern);
        const auto n = std::stoi(match[1]);
        const auto from = std::stoi(match[2]) - 1;
        const auto to = std::stoi(match[3]) - 1;
        for (int i = 0; i < n; i++) {
        const auto c = stacks[from].top();
        stacks[from].pop();
        stacks[to].push(c);
        }
    }

    for (const auto& stack : stacks) {
        if (!stack.empty()) {
        std::cout << stack.top();
        } else {
        std::cout << ' ';
        }
    }

    std::cout << '\n';
    return 0;
}