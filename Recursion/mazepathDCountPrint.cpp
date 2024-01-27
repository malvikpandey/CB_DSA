/*
Take as input N1 and N2, both numbers. N1 and N2 is the number of rows and columns on a rectangular board. Our player starts in top-left corner of the board and must reach bottom-right corner. In one move the player can move 1 step horizontally (right) or 1 step vertically (down) or 1 step diagonally (south-east).

Write a recursive function which:
a. Returns the count of different ways the player can travel across the board. Print the value returned.
b. Prints moves for all valid paths across the board.

Input Format
Enter the number of rows N1 and number of columns N2

Constraints
None

Output Format
Display the total number of paths and print all the possible paths in a space separated manner

Sample Input
3
3

Sample Output
VVHH VHVH VHHV VHD VDH HVVH HVHV HVD HHVV HDV DVH DHV DD
13
*/

#include <iostream>
#include <vector>

using namespace std;

int countPath(vector<char> path, int r, int c, int i, int j){
    //base case
    if(i == r || j == c) {
        return 0;
    }
    
    if(i == r-1 && j == c-1) {
        return 1;
    }
    //recursive case
    path.push_back('V');
    int vT = 0;
    vT += countPath(path, r, c, i+1, j);
    path.pop_back();

    path.push_back('H');
    int hT = 0;
    hT += countPath(path, r, c, i, j+1);
    path.pop_back();

    path.push_back('D');
    int dT = 0;
    dT += countPath(path, r, c, i+1, j+1);
    path.pop_back();

    return vT + hT + dT;

}

void printPath(vector<char> path, int r, int c, int i, int j){
    //base case
    if(i == r || j == c) {
        return;
    }

    if(i == r-1 && j == c-1) {
        for(char ch : path) {
            cout<<ch;
        }
        cout<<" ";
        return;
    }
    //recursive case
    path.push_back('V');
    printPath(path, r, c, i+1, j);
    path.pop_back();

    path.push_back('H');
    printPath(path, r, c, i, j+1);
    path.pop_back();

    path.push_back('D');
    printPath(path, r, c, i+1, j+1);
    path.pop_back();

}

int main(){
    int r;
    cin>>r;
    int c;
    cin>>c;
    vector<char> path;

    printPath(path, r, c, 0, 0);
    cout<<endl;
    cout<<countPath(path, r, c, 0, 0);
    return 0;
}