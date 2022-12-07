#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string part1();
string part2();

int main() {
    printf("Number of characters for part 1: %s\n", part1().c_str());
    printf("Number of characters for part 2: %s\n", part2().c_str());
 
    return 0;
}

string part1() {
    ifstream file ("./assets/problem_input.txt"); 
    string line, result;
    getline(file, line);

    constexpr int n = 4;
    int count = 0;
    array<int, 26> counter = {};

    for (int i = 0; i < n - 1; i++) {
      if (counter[line[i] - 'a'] == 0) count++;
      counter[line[i] - 'a'] += 1;
    }
    for (unsigned long i = n - 1; i < line.size(); i++) {
      if (counter[line[i] - 'a'] == 0) count++;
      counter[line[i] - 'a'] += 1;

    if (count == n) {
      result.append(to_string(i + 1));
      break;
    }

    counter[line[i- n + 1] - 'a'] -= 1;
    if (counter[line[i- n + 1] - 'a'] == 0) {
      count--;
    }
    }

    return result;
}

string part2() {
    ifstream file ("./assets/problem_input.txt"); 
    string line, result;
    getline(file, line);

    constexpr int n = 14;
  int count = 0;
  std::array<int, 26> counter = {};

  for (int i = 0; i < n - 1; i++) {
    if (counter[line[i] - 'a'] == 0) count++;
    counter[line[i] - 'a'] += 1;
  }
  for (unsigned long i = n - 1; i < line.size(); i++) {
    if (counter[line[i] - 'a'] == 0) count++;
    counter[line[i] - 'a'] += 1;
    if (count == n) {
      result.append(to_string(i + 1));
      break;
    }
    counter[line[i- n + 1] - 'a'] -= 1;
    if (counter[line[i- n + 1] - 'a'] == 0) {
      count--;
    }
  }

    return result;
}