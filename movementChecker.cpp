#include <iostream>
#include "movementChecker.h"
using namespace std;

static int pathRow[] = {2, 1, -1, -2, -2, -1, 1, 2};
static int pathCol[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(int **chessboard, int newRow, int newCol){
    return newCol<8&& newCol>0&&newRow<8&& newRow>0;
}

bool knightMove(int **chessboard, int row, int col, int move) {
    // end statement - print array
    if (move==64){
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                cout << chessboard[i][j];
                cout<< ", ";
            }
            cout << "" << endl;
        }
        return true;
    }else{
        for(int i =0;i<8;++i){
            //get coordinates for possible move
            int newRow = row + pathRow[i];
            int newCol = col + pathCol[i];
            if(isValid(chessboard,newRow,newCol)){
                ++move;
                chessboard[newRow][newCol] = move;
                if(knightMove(chessboard,newRow,newCol,move)){
                    return true;
                }
                --move;
                chessboard[newRow][newCol] = 0;
            }
        }
    }
    return false;
}