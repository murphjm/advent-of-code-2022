#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part1();
int part2();

int main() {
    printf("Sum of the priorities: %d\n", part1());
    printf("Sum of the badges: %d\n", part2());
}

int part1() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    int sum = 0;

    while(std::getline(file, line)) {
        const auto c = *std::find_first_of(std::begin(line), std::next(std::begin(line), line.size()/2),
                                        std::next(std::begin(line), line.size()/2), std::end(line));

        if (c >= 'a') {
            sum += c - 'a' + 1;
        } else {
            sum += c - 'A' + 1 + 26;
        }
    }

    return sum;
}
    

int part2() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    int sum = 0;

    std::array<int, 58> counter;
    std::fill(std::begin(counter), std::end(counter), 0);
    while(std::getline(file, line)) {
        std::sort(std::begin(line), std::end(line));
        line.erase(std::unique(std::begin(line), std::end(line)), std::end(line));
        for (const auto c : line) {
            counter[c - 'A'] += 1;
            if (counter[c - 'A'] == 3) {
                if (c >= 'a') {
                    sum += c - 'a' + 1;
                } else {
                    sum += c - 'A' + 1 + 26;
                }
                
                std::fill(std::begin(counter), std::end(counter), 0);
                break;
            }
        }
  }

  return sum;
}