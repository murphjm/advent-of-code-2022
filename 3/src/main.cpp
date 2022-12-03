#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int part1();

int main() {
    printf("Sum of the priorities: %d\n", part1());
}

int part1() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    int sum = 0;

    while(std::getline(file, line)) {
        const auto c = *std::find_first_of(std::begin(line), std::next(std::begin(line), line.size()/2),
                                        std::next(std::begin(line), line.size()/2), std::end(line));

        printf("%c\n", c);
        if (c >= 'a') {
            sum += c - 'a' + 1;
        } else {
            sum += c - 'A' + 1 + 26;
        }
    }

    return sum;
}
    