/*
Given an integer N, now you have to convert all zeros of N to 5.

Input Format
The first Line takes input integer N, denoting the number.

Constraints
1<=N<=10000

Output Format
Print the number after replacing all 0's with 5.

Sample Input
103

Sample Output
153

Explanation
Testcase 1: after replacing 0 with 5 ,number will become 153.
Testcase 2: there is no zero in number so it will remain same.
*/

#include<iostream>
#include<string>

using namespace std;

string nStr = "";

void repZeroToFive(string str, int i){
    //base case
    if(str[i] == '\0'){
        return;
    }
    //recursive case

    if(str[i] == '0'){
        nStr += '5';
    }else{
        nStr += str[i];
    }

    repZeroToFive(str, i+1);
}

int main(){
    int n;
    cin>>n;
    string str = to_string(n);
    repZeroToFive(str, 0);

    n = stoi(nStr);
    cout<<n<<endl;
    return 0;
}