#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>

using namespace std;

char board[8][8] = {
'R','N','B','Q','K','B','N','R',
'P','P','P','P','P','P','P','P',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'p','p','p','p','p','p','p','p',
'r','n','b','q','k','b','n','r'};

void swap(char board[8][8], int inRow, int inCol, int outRow, int outCol) {
    char tmp = board[inRow][inCol];
    board[inRow][inCol] = board[outRow][outCol];
    board[outRow][outCol] = tmp;
}

void printBoard(char board[8][8]) {
    cout << "# a b c d e f g h " << endl;
    for(int i = 0; i <= 7; i++) {
        cout << 8 - i << " ";
        for(int j = 0; j <= 7; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMoveRook(int inCol, int inRow, int outCol, int outRow, char board[8][8]) {
    int smallCol = min(inCol, outCol);
    int smallRow = min(inRow, outRow);
    int maxCol = max(inCol, outCol);
    int maxRow = max(inRow, outRow);
    if(inRow == outRow) {
        for(int i = smallCol + 1; i < maxCol; i++) {
            if(board[inRow][i] != '-') {
                return false;
            }
        }
        return true;
    }
    else if(outCol == inCol) {
        for(int i = smallRow + 1; i < maxRow; i++) {
            if(board[i][inCol] != '-') {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool isValidMoveBishop(int inCol, int inRow, int outCol, int outRow, char board[8][8]) {
    int rowDiff = outRow - inRow;
    int colDiff = outCol - inCol;
    if(abs(rowDiff) != abs(colDiff)) {
        return false;
    }
    else {
        for (int i = 0; i < count; ++i){
            /* code */
        }
        for (int i = 0; i < count; ++i){
            /* code */
        }
        for (int i = 0; i < count; ++i) {
            /* code */
        }
        for (int i = 0; i < count; ++i){
            /* code */
        }


        return true;
    }
}

bool isValidMove(int inCol, int inRow, int outCol, int outRow, char board[8][8]) {
    if(board[inRow][inCol] == '-') {
        return false;
    }
    else {
        if((board[inRow][inCol] == 'R' || board[inRow][inCol] == 'r') && isValidMoveRook(inCol, inRow, outCol, outRow, board)) {
        return true;
        }   
    }
}


void movePiece(char board[8][8]) {
    string input;
    string output;
    cout << "Please enter your piece position : ";
    cin >> input;
    cout << "Please enter where you want to place your piece : ";
    cin >> output;

    int inCol = input[0] - 'a';
    int inRow = 7 - (input[1] - '1');
    int outCol = output[0] - 'a';
    int outRow = 7 - (output[1] - '1');
    while(!isValidMove(inCol, inRow, outCol, outRow, board)) {
        cout << "Invalid input try again" << endl;
        cout << "Please enter your piece position : ";
        cin >> input;
        cout << "Please enter where you want to place your piece : ";
        cin >> output;
        inCol = input[0] - 'a';
        inRow = 7 - (input[1] - '1');
        outCol = output[0] - 'a';
        outRow = 7 - (output[1] - '1');
    }
    if(board[outRow][outCol] == '-') {
        swap(board, inRow, inCol, outRow, outCol);
    }
    else {
        if(isupper(board[inRow][inCol]) != isupper(board[outRow][outCol])) {
            board[outRow][outCol] = board[inRow][inCol];
            board[inRow][inCol] = '-';
        }
    }
}
 
int main() {
    printBoard(board);
    while (true) {
        movePiece(board);
        printBoard(board);
    }
} 


