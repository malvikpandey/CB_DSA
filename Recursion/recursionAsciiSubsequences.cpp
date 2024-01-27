/*
Take as input str, a string. We are concerned with all the possible ascii-subsequences of str. E.g. “ab” has following ascii-subsequences “”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

a. Write a recursive function which returns the count of ascii-subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible ascii-subsequences for a given string (void is the return type for function).

Input Format
Enter the string

Constraints
None

Output Format
Display the number of ASCII-subsequences and display all the ASCII- subsequences

Sample Input
ab

Sample Output
 b 98 a ab a98 97 97b 9798
9
*/

#include <iostream>
#include <cstring>

using namespace std;

int count = 0;
void printASCIISubsequences(string input, string output, int i) {
    //base case
    if(input[i] == '\0') {
        cout<<output<<" ";
        count++;
        return;
    }

    //recursive case
    char ch = input[i];

    printASCIISubsequences(input, output, i+1);// excluding ch
    printASCIISubsequences(input, output + ch, i+1);// including ch
    printASCIISubsequences(input, output + to_string(int(ch)), i+1);// including ch converting it into ascii

}



int main() {
    string input;
    cin >> input;

    string output="";

    printASCIISubsequences(input, output, 0);
    cout << endl;

    cout<<count;

    return 0;
}