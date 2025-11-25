#include <iostream>
#include <string>
#include <array>

// ********* Prototypes **********

void showGameBoard(std::array<std::string, 9>& gameboard);

void updateMove(std::string playerName, std::string marker, std::array<std::string, 9>& gameboard);

bool checkEndGameConditions(std::array<std::string, 9>& gameboard, std::string playerOne, std::string playerTwo);


// ******** Main *********
int main() {
    
    // declare variables
    std::string playerOne; //holds player one's name
    std::string playerTwo; // holds player two's name
    std::array<std::string, 9> gameboard = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
    bool gameOver = false;


    // get player info
    std::cout << "Enter Player One's name: ";
    std::cin >> playerOne;
    std::cout << "\n" << playerOne << " will use X." << "\n" << "\n";

    std::cout << "Enter Player Two's name: ";
    std::cin >> playerTwo;
    std::cout << "\n" << playerTwo << " will use O." << "\n" << "\n";

    // game loop
    while (gameOver == false) {
        showGameBoard(gameboard);

        // Player One's Move
        updateMove(playerOne, "X", gameboard);

        gameOver = checkEndGameConditions(gameboard, playerOne, playerTwo);
        if (gameOver == true) {
            break;
        }

        showGameBoard(gameboard);

        // Player Two's Move
        updateMove(playerTwo, "O", gameboard);

        gameOver = checkEndGameConditions(gameboard, playerOne, playerTwo);

    }
    
    return 0;
}

// ******** Functions **********
void showGameBoard(std::array<std::string, 9>& gameboard) {
    for (int i = 0; i <= 8; i++){
        std::cout << gameboard[i];

        if (i == 2 || i ==5){
            std::cout << "\n";
            std::cout << "---------";
            std::cout << "\n";
        } else if (i == 8){
            std::cout << "\n";
        }
        else {
            std::cout << " | ";
        }
    }
}

void updateMove(std::string playerName, std::string marker, std::array<std::string, 9>& gameboard) {
    int position;  // holds array index to update
    std::string positionString;

    // get new move
    std::cout << playerName << ", please enter a position number (0-8): ";
    std::cin >> positionString;
    position = std::stoi(positionString);

    // update gameboard
    gameboard[position] = marker;


}

bool checkEndGameConditions(std::array<std::string, 9>& gameboard, std::string playerOne, std::string playerTwo) {
    std::string winningMarker;
    bool won = false;
    
    // check for wins
    // rows
    if (gameboard[0] == gameboard[1] && gameboard[2] == gameboard[1]) {
        winningMarker = gameboard[0];
        won = true;
    }

    if (gameboard[3] == gameboard[4] && gameboard[5] == gameboard[3]) {
        winningMarker = gameboard[4];
        won = true;
    }

    if (gameboard[6] == gameboard[7] && gameboard[8] == gameboard[6]) {
        winningMarker = gameboard[7];
        won = true;
    }
    
    // columns
    if (gameboard[0] == gameboard[3] && gameboard[3] == gameboard[6]) {
        winningMarker = gameboard[0];
        won = true;
    }

    if (gameboard[1] == gameboard[4] && gameboard[7] == gameboard[4]) {
        winningMarker = gameboard[4];
        won = true;
    }

    if (gameboard[2] == gameboard[5] && gameboard[5] == gameboard[8]) {
        winningMarker = gameboard[8];
        won = true;
    }

    // diagonal
    if (gameboard[0] == gameboard[4] && gameboard[8] == gameboard[4]) {
        winningMarker = gameboard[4];
        won = true;
    }

    if (gameboard[2] == gameboard[4] && gameboard[6] == gameboard[4]) {
        winningMarker = gameboard[4];
        won = true;
    }

    // display win results if win found
    if (won == true) {
        
        if (winningMarker == "X"){
            std::cout << "\n" << playerOne << " wins!";
            std::cout << "\n" << "Game Over" << "\n";
        } 
        else {
            std::cout << "\n" << playerTwo << " wins!";
            std::cout << "\n" << "Game Over" << "\n";
        }

        return true;
    }
    

    // check for draw
    bool noNumbers = true;   // updates if we find a number 
    for (int i = 0; i < 9; i++) {
        if (gameboard[i] != "X" && gameboard[i] != "O") {
            noNumbers = false;
        }
    }

    if (noNumbers == true) {
        std::cout << "It's a Draw!";
        std::cout << "\n" << "Game Over";
        return true;
    }

    // default
    return false;
}