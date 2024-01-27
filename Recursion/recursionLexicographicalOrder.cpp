/*
Take as input N, a number. Write a recursive function which prints counting from 0 to N in lexicographical order. In lexicographical (dictionary) order 10, 100 and 109 will be printed before 11.

Input Format
Enter a number N.

Constraints
None

Output Format
Display all the numbers upto N in a lexicographical order

Sample Input
10

Sample Output
0 1 10 2 3 4 5 6 7 8 9 
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;



void lexoOrder(int i, int n, vector<int>& ans){
    //base case
    if(i > n){
        return;
    }

    //recursive case
    ans.push_back(i);
    for(int j=0; j<10; j++){
        lexoOrder(i*10+j, n, ans);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    if(n>0){
        ans.push_back(0);
    }

    for(int i=1; i <= 9; i++){
        lexoOrder(i, n, ans);
    }
    
    for(int s : ans){
        cout<<s<<" ";
    }
    return 0;
}