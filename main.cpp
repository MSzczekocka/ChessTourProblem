#include <iostream>
#include "movementChecker.h"
using namespace std;

int main() {
    int** chessboard = new int*[8];
    for(int i=0;i<8;++i){
        chessboard[i] = new int[8];
    }

    for (int i = 0;i < 8;++i) {
        for(int j=0;j<8;++j){
            chessboard[i][j] = 0;
        }
    }
    chessboard[0][0] =1;

    knightMove(chessboard,0,0,1);
    return 0;
}
