/*
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125

Sample Output
[aabe, aay, ale, kbe, ky]
*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char map[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void codeOfString(string input, string output, vector<string>& ans, int i) {
    //base case
    if(input[i] == '\0') {
        ans.push_back(output);
        cout<<output<<" ";
        return;
    }

    //recursive case
    int currIdx = input[i]-'0';

    if(currIdx != 0){
        output += 'a' + currIdx - 1;
        codeOfString(input, output, ans, i+1);
        output.resize(output.size()-1);
    }

    if(i+1 < input.size()) {
        int doubleDigit = stoi(input.substr(i, 2));
        if(doubleDigit>=10 && doubleDigit<=26){
            output += 'a' + doubleDigit - 1;
            codeOfString(input, output, ans, i+2);
            output.resize(output.size()-1);
        }

    }

}

int main() {
    string input;
    cin>>input;

    vector<string> ans;
    string output = "";

    codeOfString(input, output, ans, 0);

    return 0;
}