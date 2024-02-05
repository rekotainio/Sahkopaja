/*
Tekijät: Joonatan Linkola, Reko Tainio, Niklas Wall, Elias Elonheimo
Projekti: 2048-peli, ELEC-A4010 Sähköpaja, kevät 2024
Lähteet: alkuperäinen peli selaimessa: https://play2048.co/
*/




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int board[4][4] = {0};

void printBoard() {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << board[i][j] << " ";
            }
        std::cout << std::endl;
    }

}

void insertToRandomPosition() { // Initialize the 4x4 board with zeros

    srand(time(NULL));

    int row, col;
    do {
        // Generate random row and column indices
        row = rand() % 4;
        col = rand() % 4;
    } while (board[row][col] != 0);

    board[row][col] = (1 + (rand() % 2)) * 2;
    
    // Printing the board
    //printBoard();

}




void moveUp(){

    bool moved;
    do {
        moved = false; // Assume no movement initially
        for (int col = 0; col < 4; ++col) {
            bool combined = false; // Flag to track if a combination has already occurred in this column
            for (int row = 1; row < 4; ++row) {
                if (board[row][col] != 0) {
                    for (int r = row - 1; r >= 0; --r) {
                        if (board[r][col] == 0) {
                            std::swap(board[r][col], board[row][col]);
                            moved = true; // Mark as moved
                        } else if (board[r][col] == board[row][col] && !combined) {
                            board[r][col] *= 2; // Sum the two equal numbers
                            board[row][col] = 0; // Set the current element to zero
                            combined = true; // Mark as combined
                            moved = true; // Mark as moved
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } while (moved);
    insertToRandomPosition();
    

}

void moveDown(){

    bool moved;

    do {
    moved = false; // Assume no movement initially
    for (int col = 0; col < 4; ++col) {
        bool combined = false; // Flag to track if a combination has already occurred in this column
        for (int row = 2; row >= 0; --row) {
            if (board[row][col] != 0) {
                for (int r = row + 1; r < 4; ++r) {
                    if (board[r][col] == 0) {
                        std::swap(board[r][col], board[row][col]);
                        moved = true; // Mark as moved
                    } else if (board[r][col] == board[row][col] && !combined) {
                        board[r][col] *= 2; // Sum the two equal numbers
                        board[row][col] = 0; // Set the current element to zero
                        combined = true; // Mark as combined
                        moved = true; // Mark as moved
                        break;
                    } else {
                        break;
                        }
                    }
                }
            }
        }
    } while (moved);

    insertToRandomPosition();

}

void moveLeft(){

    bool moved;

    do {
    moved = false; // Assume no movement initially
    for (int row = 0; row < 4; ++row) {
        bool combined = false; // Flag to track if a combination has already occurred in this row
        for (int col = 1; col < 4; ++col) {
            if (board[row][col] != 0) {
                for (int c = col - 1; c >= 0; --c) {
                    if (board[row][c] == 0) {
                        std::swap(board[row][c], board[row][col]);
                        moved = true; // Mark as moved
                    } else if (board[row][c] == board[row][col] && !combined) {
                        board[row][c] *= 2; // Sum the two equal numbers
                        board[row][col] = 0; // Set the current element to zero
                        combined = true; // Mark as combined
                        moved = true; // Mark as moved
                        break;
                    } else {
                        break;
                        }
                    }
                }
            }
        }
    } while (moved);
    insertToRandomPosition();


}

void moveRight(){

    bool moved;


    do {
    moved = false; // Assume no movement initially
    for (int row = 0; row < 4; ++row) {
        bool combined = false; // Flag to track if a combination has already occurred in this row
        for (int col = 2; col >= 0; --col) {
            if (board[row][col] != 0) {
                for (int c = col + 1; c < 4; ++c) {
                    if (board[row][c] == 0) {
                        std::swap(board[row][c], board[row][col]);
                        moved = true; // Mark as moved
                    } else if (board[row][c] == board[row][col] && !combined) {
                        board[row][c] *= 2; // Sum the two equal numbers
                        board[row][col] = 0; // Set the current element to zero
                        combined = true; // Mark as combined
                        moved = true; // Mark as moved
                        break;
                    } else {
                        break;
                        }
                    }
                }
            }
        }
    } while (moved);

    insertToRandomPosition();

}









int main() {
    std::string number;
    insertToRandomPosition();
    insertToRandomPosition();
    printBoard();

    // Infinite loop to continuously read input
    while (true) {
        // Prompt the user to enter a number
        std::cout << "play with wsad keys (or enter k to exit): ";

        // Read the input from the terminal
        std::cin >> number;

        if (number == "w") {
            moveUp();
            printBoard();
        }

        if (number == "s") {
            moveDown();
            printBoard();
        }

        if (number == "a") {
            moveLeft();
            printBoard();
        }

        if (number == "d") {
            moveRight();
            printBoard();
        }

        // Check if the user entered -1 to exit
        if (number == "k") {
            std::cout << "Exiting the program..." << std::endl;
            break; // Exit the loop
        }

        // Print the number entered by the user
       // std::cout << "You entered: " << number << std::endl;
    }


    return 0;
}

