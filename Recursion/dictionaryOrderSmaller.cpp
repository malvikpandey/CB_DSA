/*
Take as input str, a string. Write a recursive function which returns all the words possible by rearranging the characters of this string which are in dictionary order smaller than the given string. The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10
All characters are unique

Output Format
Display all the words which are in dictionary order smaller than the string entered in a new line each. The output strings must be sorted.

Sample Input
cab

Sample Output
abc
acb
bac
bca

Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only four of them are lexicographically less than "cab". We print them in lexicographical order.
*/
#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> ans;

void dictOrder(string str, int i){
    //base case
    if(str[i] == '\0'){
        return;
    }

    //recursive case
    int n = str.size();

    for(int j=i; j<n; j++){
        swap(str[i], str[j]);
        ans.insert(str);
        dictOrder(str, i+1);
        swap(str[i], str[j]); //backtracking
    }

}

int main(){
    string str;
    cin>>str;

    dictOrder(str, 0);

    for(string a : ans){
        if(a < str){
            cout<<a<<endl;
        }
    }
    return 0;
}