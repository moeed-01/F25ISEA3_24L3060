//#include <iostream>
//using namespace std;
//
//const int SIZE = 3;
//void printBoard(char board[SIZE][SIZE]) {
//    cout << endl << "Current Board:" << endl;
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            cout << " " << board[i][j] << " ";
//            if (j < SIZE - 1) cout << "|";
//        }
//        cout << endl;
//        if (i < SIZE - 1) cout << "---+---+---" << endl;
//    }
//}
//bool checkWin(char board[SIZE][SIZE], char player) {
//    for (int i = 0; i < SIZE; i++) {
//        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
//            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
//            return true;
//    }
//    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
//        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
//        return true;
//    return false;
//}
//
//// Check  if all cells are filled
//bool isDraw(char board[SIZE][SIZE]) {
//    for (int i = 0; i < SIZE; i++)
//        for (int j = 0; j < SIZE; j++)
//            if (board[i][j] == ' ') return false;
//    return true;
//}
//
//bool makeMove(char board[SIZE][SIZE], char player) {
//    int row, col;
//
//    cout << endl << "Player " << player << ", enter your move (row column): ";
//    cin >> row >> col;
//
//    if (cin.fail()) {
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << "Invalid input format. Example: 1 2" << endl;
//        return false;
//    }
//
//    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
//        cout << "Invalid position. Must be between 0 and 2." << endl;
//        return false;
//    }
////check for empty cell/position
//    if (board[row][col] != ' ') {
//        cout << "Cell already taken. Try another." << endl;
//        return false;
//    }
//
//    // Make the move
//    board[row][col] = player;
//    return true;
//}
//int main() {
//    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
//    bool gameOver = false;
//    char player1, player2;
//
//    cout << "Welcome to Two-Player Tic Tac Toe!" << endl;
//    cout << "Players will select their symbol (X or O) at the start." << endl;
//
//    while (true) {
//        cout << "Player 1, choose your symbol (X or O): ";
//        cin >> player1;
//        if (player1 >= 'a' && player1 <= 'z') {
//            player1 -= 32;
//        }
//        if (player1 == 'X' || player1 == 'O') {
//            break;
//        }
//        else {
//            cout << "Invalid symbol! Only X or O allowed." << endl;
//        }
//    }
//    if (player1 == 'X') {
//        player2 = 'O';
//    } else {
//        player2 = 'X';
//    }
//    cout << "Player 1 is '" << player1 << "', Player 2 is '" << player2 << "'." << endl;
//
//    int turn = 0; // 0 for player1, 1 for player2
//
//    while (!gameOver) {
//        printBoard(board);
//
//        char currentPlayer;
//        if (turn % 2 == 0) {
//            currentPlayer = player1;
//        } else {
//            currentPlayer = player2;
//        }
//        if (!makeMove(board, currentPlayer)) continue; // repeat if invalid move.Current player will takes its turn again
//
//        // Check for win/draw
//        if (checkWin(board, currentPlayer)) {
//            printBoard(board);
//            cout << endl << "Player " << currentPlayer << " wins!" << endl;
//            gameOver = true;
//        }
//        else if (isDraw(board)) {
//            printBoard(board);
//            cout << endl << "Game drawn!" << endl;
//            gameOver = true;
//        }
//        turn++;
//    }
//
//    cout << endl << "Thanks for playing!" << endl;
//    return 0;
//}
