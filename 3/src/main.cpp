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
            int middle = line.length() / 2;
            string left = line.substr(0, middle);
            string right = line.substr(middle, line.length());

            for(unsigned long i = 0; i < left.length() / 2; i++) {
                if(isupper(left[i])) {
                    letters[(left[i] - 'A') + 26] = 1;
                } else {
                    letters[left[i] - 'a'] = 1;
                }

                if(isupper(right[i])) {
                    letters[(right[i] - 'A') + 26]++;
                } else {
                    letters[right[i] - 'a']++;
                }
            }

            for(int i = 0; i < 52; i++) {
                // printf("%d", letters[i]);
                int count = letters[i] / 2;
                if(count >= 1) {
                    sum += (letters[i] + 1) * count;
                }
            }

            // printf("\n\n");
        }
    }
    else
        cout<<"Couldn't open the input file\n";

    file.close();

    return sum;
}
    