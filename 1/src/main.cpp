#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file ("./assets/problem1_input.txt"); 
    vector<int> elves;
    string line;
    int calories = 0;

    if(file.is_open()) 
    {
        while (getline(file, line)) {
            if(strcmp(line.c_str(), "") == 0) {
                elves.push_back(calories);
                calories = 0;
            } else {
                calories += atoi(line.c_str());
            }
        }
    }
    else
        cout<<"Couldn't open the file\n";

    sort(elves.begin(), elves.end(), greater<int>());
    printf("Highest calories: %d\n", elves[0]);
    printf("Highest calories of top 3 elves: %d\n", elves[0] + elves[1] + elves[2]);
}