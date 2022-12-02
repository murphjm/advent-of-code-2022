#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int getWinner(char player1, char player2);

int main() {
    ifstream file ("./assets/problem2_input.txt"); 

    string line;
    int score = 0;

    if(file.is_open()) 
    {
        while (getline(file, line)) {
            printf("%c %c\n", line[0], line[2]);

            switch (line[2])
            {
            case 'X': // Rock
                score += 1 + getWinner(line[0], 'X');
                break;
            case 'Y': // Paper
                score += 2 + getWinner(line[0], 'Y');
                break;
            case 'Z': // Scissors
                score += 3 + getWinner(line[0], 'Z');
                break;
            
            default:
                break;
            }
        }
    }
    else
        cout<<"Couldn't open the file\n";

    printf("Total score: %d\n", score);

}

int getWinner(char player1, char player2) {
    int score = 0;

    // 
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