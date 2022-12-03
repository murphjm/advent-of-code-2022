#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int part1();
int part2();
int getWinner(char player1, char player2);

int main() {
    printf("Total score part 1: %d\n", part1());
    printf("Total score part 2: %d\n", part2());
}

int part1() {

    ifstream file ("./assets/problem_input.txt"); 

    string line;
    int score = 0;

    if(file.is_open()) 
    {
        while (getline(file, line)) {
            score += getWinner(line[0], line[2]) + line[2] - 'W';
        }
    }
    else
        cout<<"Couldn't open the input file\n";

    file.close();

    return score;
}


int part2() {
    ifstream file ("./assets/problem_input.txt"); 

    string line;
    int score = 0;
    unordered_map<char, char> is_beat_by;
    unordered_map<char, char> wins_against;

    is_beat_by['A'] = 'Z';
    is_beat_by['B'] = 'X';
    is_beat_by['C'] = 'Y';

    wins_against['A'] = 'Y';
    wins_against['B'] = 'Z';
    wins_against['C'] = 'X';


    if(file.is_open()) 
    {
        while (getline(file, line)) {
            // X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win

            // A Y -> A X -> 1 + 3 = 4
            // B X -> B X -> 1 + 0 = 1
            // C Z -> C X -> 1 + 6 = 7

            // A X -> A Z -> 3 + 0 = 3
            // B X -> B X -> 1 + 0 = 1
            // C X -> C Y -> 2 + 0 = 2

            // A Z -> A Y -> 2 + 6 = 8
            // B Z -> B Z -> 3 + 6 = 9
            // C Z -> C X -> 1 + 6 = 7

            switch (line[2])
            {
                case 'X': // Rock
                    score += is_beat_by[line[0]] - 'W';
                    break;
                case 'Y': // Paper
                    score += int(line[0]) - '@' + 3;
                    break;
                case 'Z': // Scissors
                    score += wins_against[line[0]] - 'W' + 6;
                    break;
                
                default:
                    break;
            }
        }
    }
    else
        cout<<"Couldn't open the input file\n";

    file.close();

    return score;
}


int getWinner(char player1, char player2) {
    int score = 0;
    if(player2 == 'X') {
        // Rock
        if(player1 == 'A') {
            score += 3;
        // Paper
        } else if(player1 == 'B') {
            score += 0;
        // Scissors
        } else {
            score += 6;
        }
    } else if(player2 == 'Y') {
        // Rock
        if(player1 == 'A') {
            score += 6;
        // Paper
        } else if(player1 == 'B') {
            score += 3;
        // Scissors
        } else {
            score += 0;
        }
    } else if(player2 == 'Z') {
        // Rock
        if(player1 == 'A') {
            score += 0;
        // Paper
        } else if(player1 == 'B') {
            score += 6;
        // Scissors
        } else {
            score += 3;
        }
    }

    return score;
}
    