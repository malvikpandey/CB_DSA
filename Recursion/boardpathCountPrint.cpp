/*
Take as input N, a number. N is the size of a snakes and ladder board (without any snakes and ladders). Take as input M, a number. M is the number of faces of the dice.

a. Write a recursive function which returns the count of different ways the board can be traveled using the dice. Print the value returned.

b. Write a recursive function which prints dice-values for all valid paths across the board (void is the return type for function).

Input Format
Enter a number N (size of the board) and number M(number of the faces of a dice)

Constraints
M<=100
N<=100
M^N <=10^9

Output Format
Display the number of paths and print all the paths in a space separated manner

Sample Input
3
3

Sample Output
111 12 21 3 
4
*/

#include <iostream>
#include <vector>

using namespace std;

int countBoard(int n, int m, vector<int>& out, int sum) {    
    //base case
    if(sum == n) {
        return 1;
    }

    //recursive case
    int count = 0;
    for(int j=1; j<=m && sum<n; j++) {
        out.push_back(j);
        sum += j;    
        count += countBoard(n, m, out, sum);
        sum -= j;
        out.pop_back();
    }

    return count;
}

void printBoard(int n, int m, vector<int>& out, int sum) {    
    //base case
    if(sum == n) {
       for(int i=0; i<out.size(); i++){
            cout<<out[i];
        }
        cout<<" ";
        return;
    }

    //recursive case
    for(int j=1; j<=m && sum<n; j++) {
        out.push_back(j);
        sum += j;    
        printBoard(n, m, out, sum);
        sum -= j;
        out.pop_back();
    }
}

int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> out;

    printBoard(n ,m ,out, 0);
    cout<<endl;

    cout<<countBoard(n ,m ,out, 0);


    return 0;
}