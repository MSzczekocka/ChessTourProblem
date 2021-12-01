#include <iostream>
#include "movementChecker.h"

using namespace std;
#define N 8

int static xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int static yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int isValid(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == 0);
}

void printChess(int chessboard[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << chessboard[x][y] << " ";
        cout << endl;
    }
}

int checkPath(int x, int y, int move, int chessboard[N][N]) {
    int nextX, nextY;
    if (move == 65) {
        return 1;
    } else {
        for (int k = 0; k < 8; k++) {
            nextX = x + xMove[k];
            nextY = y + yMove[k];
            if (isValid(nextX, nextY, chessboard)) {
                chessboard[nextX][nextY] = move;
                if (checkPath(nextX, nextY, move + 1, chessboard) == 1) {
                    return 1;
                } else {
                    chessboard[nextX][nextY] = 0;
                }
            }
        }
        return 0;
    }
}

int findPath() {
    int chessboard[N][N] = {0};
    chessboard[0][0] = 1;

    if (checkPath(0, 0, 2, chessboard) == 0) {
        cout << "Solution does not exist";
        return 0;
    } else {
        printChess(chessboard);
        return 1;
    }
}

