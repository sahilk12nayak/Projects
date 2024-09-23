#include <bits/stdc++.h>
using namespace std;

char board[3][3];
char currentPlayer;

void printBoard(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << board[i][j];
            if (j<2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i<2){
            cout << "---------" << endl;
        }
    }
}

bool checkWin(){
    for (int i=0; i<3; i++){
        if (board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer){
            return true;
        }
        if (board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer){
            return true;
        }
    }
    if (board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer){
        return true;
    }
    if (board[2][0]==currentPlayer && board[1][1]==currentPlayer && board[0][2]==currentPlayer){
        return true;
    }
    return false;
}

bool checkDraw(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout << "\n\t\t----->TIC-TAC-TOE GAME<-----" << endl << endl << endl;
    while (true){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        cout << "--->Player X will start the game." << endl;
        while (true){
            cout << "Current Board:" << endl;
            printBoard();

            int row, col;
            cout << endl << "Player " << currentPlayer << ", enter your move (row, column):" ;
            cin >> row >> col;
            if (row<0 || row>=3 || col<0 || col>=3 || board[row][col]!=' '){
                cout << endl << "Invalid move. Try again!" << endl << endl;
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!!!" << endl;
                break;
            }
            else if (checkDraw()){
                cout << "Its a draw." << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        string playAgain;
        cout << "--->Do you want to play again? (Yes/No) : ";
        cin >> playAgain;
        if (playAgain!="Yes"){
            cout << "Thanks for playing. Goodbye!" << endl;
            break;
        }

    }


    return 0;
}
