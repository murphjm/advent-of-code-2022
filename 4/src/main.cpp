#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int part1();
vector<string> split(const string& str, const string& delim);

int main() {
    printf("Number of fully contained pairs: %d\n", part1());
}

int part1() {
    ifstream file ("./assets/problem_input.txt"); 
    string line;
    int sum = 0;
    string sol;
    vector<string> shifts;
    vector<int> nums;

    while(std::getline(file, line)) {
        auto row = split(line, ",");
        shifts.push_back(row[0]);
        shifts.push_back(row[1]);
    }

    for(auto s: shifts) {
        replace(s.begin(), s.end(), '-', ' ');
        sol.append(s).append(" ");
    }

    stringstream ss(sol);
    
    for(int i = 0; ss >> i; ) {
        nums.push_back(i);
    }

    unsigned long l = 0;
    while(l < nums.size()) {
        auto first = nums[l];
        auto second = nums[l + 1];
        auto third = nums[l + 2];
        auto fourth = nums[l + 3];

        if((first <= third && second >= fourth) || (third <= first && fourth >= second)) {
            sum++;
        }

        l += 4;
    }

    return sum;
}

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}