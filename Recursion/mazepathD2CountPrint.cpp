/*
Take as input N. N is the number of rows and columns on a square board. Our player starts in top-left corner of the board and must reach bottom-right corner. In one move the player can move 1 step horizontally (right) or 1 step vertically (down) or 1 step diagonally (south-east). But the diagonal step is allowed only when the player is currently on one of the diagonals (there are two diagonals)

Write a recursive function which:
a. Returns the count of different ways the player can travel across the board. Print the value returned.
b. Prints moves for all valid paths across the board.

Input Format
Enter the number N.

Constraints
None

Output Format
Display the total number of paths and display all the possible paths in a space separated manner.

Sample Input
3

Sample Output
VVHH VHVH VHHV VHD HVVH HVHV HVD HHVV DVH DHV DD 
11
*/

#include <iostream>
#include <vector>

using namespace std;

int countPath(vector<char> path, int rc, int i, int j){
    //base case
    if(i == rc || j == rc) {
        return 0;
    }
    
    if(i == rc-1 && j == rc-1) {
        return 1;
    }
    //recursive case
    path.push_back('V');
    int vT = 0;
    vT += countPath(path, rc, i+1, j);
    path.pop_back();

    path.push_back('H');
    int hT = 0;
    hT += countPath(path, rc, i, j+1);
    path.pop_back();

    int dT = 0;

    if(i==j || (i+j) == rc-1) {
        path.push_back('D');
        dT += countPath(path, rc, i+1, j+1);
        path.pop_back();
    }

    return vT + hT + dT;

}

void printPath(vector<char> path, int rc, int i, int j){
    //base case
    if(i<0 || j<0){
        return;
    }

    if(i == rc || j == rc) {
        return;
    }

    if(i == rc-1 && j == rc-1) {
        for(char ch : path) {
            cout<<ch;
        }
        cout<<" ";
        return;
    }
    //recursive case
    path.push_back('V');
    printPath(path, rc, i+1, j);
    path.pop_back();

    path.push_back('H');
    printPath(path, rc, i, j+1);
    path.pop_back();

    if(i==j || (i+j) == rc-1) {
        path.push_back('D');
        printPath(path, rc, i+1, j+1);
        path.pop_back();
    }

    // if((i+j) == rc-1) {
    //     path.push_back('D');
    //     printPath(path, rc, i+1, j-1);
    //     path.pop_back();
    // }

}

int main(){
    int rc;
    cin>>rc;
    vector<char> path;

    printPath(path, rc, 0, 0);
    cout<<endl;
    cout<<countPath(path, rc, 0, 0);
    return 0;
}