#include <bits/stdc++.h>
using namespace std;

constexpr int OVERALL_SIZE = 9;
constexpr int BOX_SIZE = 3;

void display(int *board){
    for(int i = 0;i < OVERALL_SIZE * OVERALL_SIZE;i++){
        cout << board[i];
        if(i % BOX_SIZE == BOX_SIZE - 1) cout << " ";
        if(i % OVERALL_SIZE == OVERALL_SIZE - 1) cout << endl;
    }
}

bool canPut(int *board, int place, int number) {
    int row = place / OVERALL_SIZE;
    int column = place % OVERALL_SIZE;
    int box = (row / BOX_SIZE) * BOX_SIZE * OVERALL_SIZE + (column / BOX_SIZE) * BOX_SIZE;
    for(int i = 0;i < OVERALL_SIZE;i++){
        if(board[row * OVERALL_SIZE + i] == number) return false;
        if(board[column + i * OVERALL_SIZE] == number) return false;
        if(board[box + (i / BOX_SIZE) * OVERALL_SIZE + (i % BOX_SIZE)] == number) return false;
    }
    return true;
}

void solve(int *board, int place){
    bool cansolve = false;
    if(place == OVERALL_SIZE * OVERALL_SIZE){
        display(board);
        cout << endl;
        cansolve = true;
    }

    int newPlace;
    for(newPlace = place;newPlace < OVERALL_SIZE * OVERALL_SIZE;newPlace++){
        if(!board[newPlace]) break;
    }

    for(int i = 1;i <= 9;i++){
        if(canPut(board, newPlace, i)){
            board[newPlace] = i;
            solve(board, newPlace + 1);
            board[newPlace] = 0;
        }
    }
    if(newPlace == 1 && !cansolve) cout << "This Problem can be solved." << endl;
}

int main() {
    int board[OVERALL_SIZE * OVERALL_SIZE] = {
    1,0,0,0,0,7,0,9,0,
    0,3,0,0,2,0,0,0,8,
    0,0,9,6,0,0,5,0,0,
    0,0,5,3,0,0,9,0,0,
    0,1,0,0,8,0,0,0,2,
    6,0,0,0,0,4,0,0,0,
    3,0,0,0,0,0,0,1,0,
    0,4,0,0,0,0,0,0,7,
    0,0,7,0,0,0,3,0,0
    };
    solve(board, 0);
    return 0;
}