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

    if(file.is_open()) 
    {
        while (getline(file, line)) {
            int *letters = new int[52];

            for(unsigned long i = 0; i < line.length(); i++) {
                if(isupper(line[i])) {
                    letters[(line[i] - 'A') + 26]++;
                } else {
                    letters[line[i] - 'a']++;
                }
            }

            for(int i = 0; i < 52; i++) {
                int count = letters[i] / 2;
                if(count >= 1) {
                    sum += (letters[i] + 1) * count;
                }
            }
        }
    }
    else
        cout<<"Couldn't open the input file\n";

    file.close();

    return sum;
}
    