/*
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number

a. Write a recursive function which prints subsets of the array which sum to target.

b. Write a recursive function which counts the number of subsets of the array which sum to target. Print the value returned.

Input Format
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number

Constraints
None

Output Format
Display the number of subsets and print the subsets in a space separated manner.

Sample Input
3
1
2
3
3

Sample Output
1 2  3
2

Explanation
Add 2 spaces between 2 subset solutions
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;


int subProbCount(vector<int>& inp, int i, int target) {
    // Base case: If the target becomes zero, a valid subset is found
    if (target == 0) {
        return 1;
    }
    // Base case: If we reach the end of the array
    if (i == inp.size()) {
        return 0;
    }

    // Recursive case: Include the current element in the subset
    int includeCount = subProbCount(inp, i + 1, target - inp[i]);

    // Recursive case: Exclude the current element from the subset
    int excludeCount = subProbCount(inp, i + 1, target);

    return includeCount + excludeCount;

 } 

void subProbPrint(vector<int>& inp, vector<int> res, int target, int i, int sum) {
    //base case
    if(i == inp.size()){
        if(sum == target){
            for(int i : res){
                cout<<i<<" ";
            }
            cout<<"  ";
        }
        return;
    }

    //recursive case
    res.push_back(inp[i]);
    subProbPrint(inp, res, target, i+1, sum + inp[i]);
    res.pop_back();

    subProbPrint(inp, res, target, i+1, sum);
 }

int main() {
    vector<int> inp;
    int n;
    cin>>n;

    vector<int> res;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        inp.push_back(a);
    }


    int target;
    cin>>target;

    subProbPrint(inp, res, target, 0, 0);

    cout<<endl;
    cout<<subProbCount(inp, 0, target);    
            
    return 0;
}