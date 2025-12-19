#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

    // Helper to check rows, cols, and diagonals
    bool checkLine(char c1, char c2, char c3) const {
        return (c1 != ' ' && c1 == c2 && c2 == c3);
    }

public:
    TicTacToe() {
        reset();
    }

    void reset() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    // Method: Draw the state using '|', '_', and spaces/'X'/'O'
    void draw() const {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << "    |  " << board[i][1] << "   |  " << board[i][2] << " ";
            if (i < 2) cout << "\n___|___|___\n";
            else       cout << "\n       |      |       \n";
        }
        cout << endl;
    }

    // Method: Accept player move from keyboard with validation
    // Returns false if player chooses to exit
    bool makeMove() {
        int choice;
        bool valid = false;

        while (!valid) {
            cout << "Player " << currentPlayer << ", enter cell (1-9) or 0 to exit: ";
            if (!(cin >> choice)) {
                cin.clear(); // Clear error flag
                cin.ignore(1000, '\n'); // Discard bad input
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (choice == 0) return false; // Exit condition

            // Map 1-9 to row/col
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (choice >= 1 && choice <= 9 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                valid = true;
            } else {
                cout << "Invalid move (position occupied or out of range). Try again.\n";
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Method: Check game status
    // Returns: 'X'/'O' (winner), 'D' (draw), 'C' (continue)
    char checkStatus() const {
        // Rows and Columns
        for (int i = 0; i < 3; ++i) {
            if (checkLine(board[i][0], board[i][1], board[i][2])) return board[i][0];
            if (checkLine(board[0][i], board[1][i], board[2][i])) return board[0][i];
        }
        // Diagonals
        if (checkLine(board[0][0], board[1][1], board[2][2])) return board[0][0];
        if (checkLine(board[0][2], board[1][1], board[2][0])) return board[0][2];

        // Check for Draw (full board)
        bool full = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') full = false;

        if (full) return 'D';

        return 'C'; // Continue
    }
};

int t15_14() {
    TicTacToe game;
    char status = 'C';

    cout << "=== Tic-Tac-Toe ===\n";
    game.draw();

    while (status == 'C') {
        // 1. Player Move
        if (!game.makeMove()) {
            cout << "Game exited by user.\n";
            break;
        }

        // 2. Update Draw
        game.draw();

        // 3. Check Result
        status = game.checkStatus();

        if (status == 'X' || status == 'O') {
            cout << "Congratulations! Player " << status << " wins!\n";
        } else if (status == 'D') {
            cout << "It's a Draw!\n";
        } else {
            game.switchPlayer();
        }
    }

    return 0;
}