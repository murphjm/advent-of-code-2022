#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

pair<int, int> get_shifts();

int main() {
    auto solutions = get_shifts();
    printf("Number of fully contained pairs: %d\n", solutions.first);
    printf("Number of fully contained pairs: %d\n", solutions.second);
}

pair<int, int> get_shifts() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    int sum1 = 0, sum2 = 0;
    string trimmed;
    vector<int> nums;

    while(std::getline(file, line)) {
        replace(line.begin(), line.end(), ',', ' ');
        replace(line.begin(), line.end(), '-', ' ');
        trimmed.append(line).append(" ");
    }

    stringstream ss(trimmed);
    
    for(int i = 0; ss >> i;) {
        nums.push_back(i);
    }

    unsigned long l = 0;
    while(l < nums.size()) {
        auto first = nums[l];
        auto second = nums[l + 1];
        auto third = nums[l + 2];
        auto fourth = nums[l + 3];

        if((first <= third && second >= fourth) || (third <= first && fourth >= second)) {
            sum1++;
        }

        if((first <= third && second >= third) || (first <= fourth && second >= fourth) || (third <= first && fourth >= second) || (third <= second && fourth >= second)) {
            sum2++;
        }

        l += 4;
    }

    return make_pair(sum1, sum2);
}