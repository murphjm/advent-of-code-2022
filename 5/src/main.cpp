#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string part1();
string part2();

int main() {
    printf("Order for part 1: %s\n", part1().c_str());
    printf("Order for part 2: %s\n", part2().c_str());
 
    return 0;
}

string part1() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    vector<string> in;
    string result; 

    while(getline(file, line) && line[1] != '1') {
        in.push_back(line);
    }

    vector<stack<char>> stacks(line.size() / 4 + 1);
    for (int i = in.size() - 1; i >= 0; i--) {
        for (unsigned long j = 0; j < stacks.size(); j ++) {
        const int k = j * 4 + 1;
        if (in[i][k] == ' ') continue;
        stacks[j].push(in[i][k]);
        }
    }

    getline(file, line);
    const regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
    while (getline(file, line)) {
        smatch match;
        regex_match(line, match, pattern);
        const auto n = stoi(match[1]);
        const auto from = stoi(match[2]) - 1;
        const auto to = stoi(match[3]) - 1;
        for (int i = 0; i < n; i++) {
        const auto c = stacks[from].top();
        stacks[from].pop();
        stacks[to].push(c);
        }
    }

    for (const auto& stack : stacks) {
        if (!stack.empty()) {
            result.push_back(stack.top());
        }
    }

    return result;
}

string part2() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    vector<string> in;
    string result; 

    while(getline(file, line) && line[1] != '1') {
    in.push_back(line);
  }

  vector<stack<char>> stacks(line.size() / 4 + 1);
  for (int i = in.size() - 1; i >= 0; i--) {
    for (unsigned long j = 0; j < stacks.size(); j ++) {
      const int k = j * 4 + 1;
      if (in[i][k] == ' ') continue;
      stacks[j].push(in[i][k]);
    }
  }

  getline(file, line);
  const regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
  
  while (getline(file, line)) {
    smatch match;
    regex_match(line, match, pattern);
    const auto n = stoi(match[1]);
    const auto from = stoi(match[2]) - 1;
    const auto to = stoi(match[3]) - 1;
    vector<char> crates_lifted;
    for (int i = 0; i < n; i++) {
      crates_lifted.push_back(stacks[from].top());
      stacks[from].pop();
    }
    for (int i = crates_lifted.size()-1; i>=0; i--) {
      stacks[to].push(crates_lifted[i]);
    }
  }

  for (const auto& stack : stacks) {
    if (!stack.empty()) {
      result.push_back(stack.top());
    }
  }

  return result;
}