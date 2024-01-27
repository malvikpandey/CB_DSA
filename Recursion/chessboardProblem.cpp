/*
Take as input N, a number. N represents the size of a chess board. We’ve a piece standing in top-left corner and it must reach the bottom-right corner. The piece moves as follows –

a. In any cell, the piece moves like a knight. But out of the possible 8 moves for a knight, only the positive ones are valid i.e. both row and column must increase in a move.

b. On the walls (4 possible walls), the piece can move like a rook as well (in addition of knight moves). But, only the positive moves are allowed i.e. as a rook, piece can move any number of steps horizontally or vertically but in a manner, such that row or column must increase.

c. On the diagonals (2 possible diagonals), the piece can move like a bishop as well (in addition to the knight and possibly rook moves). But, only the positive moves are allowed i.e. as a bishop, piece can move in a way such that row and column must increase.

You are supposed to write the following functions

a. Write a recursive function which prints all valid paths.

b. Write a recursive function which returns the count of different distinct ways this board can be crossed. Print the value returned.

Input Format
Enter the size of the chessboard N

Constraints
None

Output Format
Display the total number of valid paths and print all the valid paths in a space separated manner

Sample Input
3

Sample Output
{0-0}K{2-1}R{2-2} {0-0}K{1-2}R{2-2} {0-0}R{0-1}K{2-2} {0-0}R{0-1}R{0-2}R{1-2}R{2-2} {0-0}R{0-1}R{0-2}R{2-2} {0-0}R{0-1}R{1-1}B{2-2} {0-0}R{0-1}R{2-1}R{2-2} {0-0}R{0-2}R{1-2}R{2-2} {0-0}R{0-2}R{2-2} {0-0}R{1-0}K{2-2} {0-0}R{1-0}R{1-1}B{2-2} {0-0}R{1-0}R{1-2}R{2-2} {0-0}R{1-0}R{2-0}R{2-1}R{2-2} {0-0}R{1-0}R{2-0}R{2-2} {0-0}R{2-0}R{2-1}R{2-2} {0-0}R{2-0}R{2-2} {0-0}B{1-1}B{2-2} {0-0}B{2-2}
18
*/

#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void chessBoard(int n, vector<vector<char>>& board, int row, int col) {
    //base case

    if(row == n-1 && col == n-1) {
        count++;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0){
                    cout<<"{"<<i<<"-"<<j<<"}";
                }
                else if(board[i][j]!='0'){
                    cout<<board[i][j];
                    cout<<"{"<<i<<"-"<<j<<"}";
                }
            }
        }
        cout<<" ";
        return;
    }
    

    //recursive case

    //Placements for Knight
    if(row+2 < n && col+1 < n) {
        // cout<<"* ";
        board[row+2][col+1] = 'K';
        chessBoard(n, board, row+2, col+1);
        board[row+2][col+1] = '0';
    }

    if(row+1 < n && col+2 < n) {
        //cout<<"# ";
        board[row+1][col+2] = 'K';
        chessBoard(n, board, row+1, col+2);
        board[row+1][col+2] = '0';
    }

    //Placements for rookie
    if(row == 0 || col == 0 || row == n-1 || col == n-1) {
        for (int i = 1; col+i < n; i++) {
            
            board[row][col+i] = 'R';
            chessBoard(n, board, row, col+i);
            board[row][col+i] = '0';
        }

        for (int i = 1; row+i < n; i++) {
            
            board[row+i][col] = 'R';
            chessBoard(n, board, row+i, col);
            board[row+i][col] = '0';
        }
    }
    

    // Placement for bishop

    if(row == col || row + col == n-1 ) {
        for (int i = 1; col+i<n && row+i<n; i++)
        {
            board[row+i][col+i] = 'B';
            chessBoard(n, board, row+i, col+i);
            board[row+i][col+i] = '0';
        }
    }
    
}

int main() {
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'0'));

    chessBoard(n, board, 0, 0);
    cout<<endl;
    cout<<count;

    return 0;
}