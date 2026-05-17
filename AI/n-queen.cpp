#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> board;
vector<bool> col, dig1, dig2;

void printBoard(){

    for(int i=0; i<N; i++){

        for(int j=0; j<N; j++){

            if(board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }

        cout << endl;
    }

    cout << endl;
}

void solve(int row){

    // All queens placed
    if(row == N){

        cout << "Solution Found\n";

        printBoard();

        return;
    }

    for(int i=0; i<N; i++){

        if(!col[i] &&
           !dig1[row+i] &&
           !dig2[row-i+N-1]){

            board[row] = i;

            col[i] = true;
            dig1[row+i] = true;
            dig2[row-i+N-1] = true;

            solve(row+1);

            // Backtracking
            col[i] = false;
            dig1[row+i] = false;
            dig2[row-i+N-1] = false;
        }
    }
}

int main(){
    cout << "Enter number of Queens: ";

    cin >> N;

    board.resize(N);

    col.resize(N,false);

    dig1.resize(2*N,false);

    dig2.resize(2*N,false);

    solve(0);

    return 0;
}