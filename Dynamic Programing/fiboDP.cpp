#include<iostream>
#include<vector>
using namespace std;

int fiboTopDown(int n, vector<int>& dp){
    //lookup
    if(dp[n] != -1){
        return dp[n];
    }

    //base case
    if(n == 0 || n == 1){
        return dp[n] = n;
    }

    //recursive case
    return dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);

}

int main(){
    int n = 7;
    vector<int> dp(n + 1, -1);

    cout<<fiboTopDown(n, dp);

}