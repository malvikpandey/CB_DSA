/*
Take as input N, the size of a chess board. We are asked to place N number of Knights in it, so that no knight can kill other.

a. Write a recursive function which returns the count of different distinct ways the knights can be placed across the board. Print the value returned.

b.Write a recursive function which prints all valid configurations (void is the return type for function).

Input Format
Enter the size of the chessboard N

Constraints
None

Output Format
Display the number of ways a knight can be placed and print all the possible arrangements in a space separated manner

Sample Input
2

Sample Output
{0-0} {0-1}  {0-0} {1-0}  {0-0} {1-1}  {0-1} {1-0}  {0-1} {1-1}  {1-0} {1-1} 
6
*/
#include <iostream>
#include <vector>

using namespace std;

int count=0;

bool isSafe(int n, vector<vector<int>> board, int i, int j) {
    if(i-2>=0 && j+1<n && i-2<n && j+1>=0 && board[i-2][j+1]==1)return false;
    if(i-1>=0 && j+2<n && i-1<n && j+2>=0 && board[i-1][j+2]==1)return false;
    if(i-1>=0 && j-2>=0 && i-1<n && j-2<n && board[i-1][j-2]==1)return false;
    if(i-2>=0 && j-1>=0 && i-2<n && j-1<n && board[i-2][j-1]==1)return false;
    return true;
}

void nKnight(int n, vector<vector<int>>& pos, int r, int row, int col) {
    
    //base case
    if(row == n) {
        return;
    }

    if(r == n) {
        count++;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(pos[i][j] == 1) {
                    cout<<"{"<<i<<"-"<<j<<"} ";
                }
            }
        }
        cout<<" ";
        return;
    }


    //recursive case
    if(col == n) {
        nKnight(n, pos, r, row+1, 0);
        return;
    }

    if(isSafe(n ,pos, row, col)) {
        pos[row][col] = 1;
        nKnight(n, pos, r+1, row, col+1);
        pos[row][col] = 0;
    }

    nKnight(n, pos, r, row, col+1);

}



int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> pos(n, vector<int>(n, 0));

    //vector<int> pos;

    nKnight(n, pos, 0, 0, 0);
    cout<<endl;

    cout<<count;
    return 0;
}