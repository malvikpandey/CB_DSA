// #include <iostream>
// #include <vector>
// using namespace std;

// void generateCodes(string input, int index, string currentCode, vector<string>& result) {
//     if (index == input.length()) {
//         result.push_back(currentCode);
//         return;
//     }

//     // Convert the current character to an integer
//     int currentNum = input[index] - '0';
//     cout<<currentNum<<" ";

//     // If the current character is not '0', add the corresponding code
//     if (currentNum != 0) {
//         char currentChar = 'a' + currentNum - 1;
//         generateCodes(input, index + 1, currentCode + currentChar, result);
//     }

//     // If there are at least two characters left in the input, check for a valid double-digit code
//     if (index + 1 < input.length()) {
//         int doubleDigit = stoi(input.substr(index, 2));
//         if (doubleDigit >= 10 && doubleDigit <= 26) {
//             char doubleDigitChar = 'a' + doubleDigit - 1;w
//             generateCodes(input, index + 2, currentCode + doubleDigitChar, result);
//         }
//     }
// }

// int main() {
//     string input;
//     cout << "Enter a number: ";
//     cin >> input;

//     vector<string> result;
//     generateCodes(input, 0, "", result);

//     cout << "Possible codes for " << input << " are:" << endl;
//     for (string code : result) {
//         cout << code << " ";
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int countSubsetsWithSum(vector<int>& arr, int index, int target) {
//     // Base case: If the target becomes zero, a valid subset is found
//     if (target == 0) {
//         return 1;
//     }
//     // Base case: If we reach the end of the array
//     if (index == arr.size()) {
//         return 0;
//     }

//     // Recursive case: Include the current element in the subset
//     int includeCount = countSubsetsWithSum(arr, index + 1, target - arr[index]);

//     // Recursive case: Exclude the current element from the subset
//     int excludeCount = countSubsetsWithSum(arr, index + 1, target);

//     return includeCount + excludeCount;
// }

// void findPairsWithSum(vector<int>& inp, int target, int i, int j) {
//     // Base case
//     if (i == inp.size() || j == inp.size()) {
//         return;
//     }

//     // Check if inp[i] and inp[j] form a pair with the target sum
//     if (inp[i] + inp[j] == target) {
//         cout << inp[i] << " " << inp[j] << "  ";
//     }

//     if(inp[i] == target) {
//         cout<<inp[i]<<"  ";
//         return;
//     }

//     if(inp[j] == target) {
//         cout<<inp[j]<<"  ";
//         return;
//     }

//     // Move to the next pair
//     findPairsWithSum(inp, target, i, j + 1);

//     // If we reach the end of the inner loop, increment i to move to the next element
//     if (j == inp.size() - 1) {
//         findPairsWithSum(inp, target, i + 1, i + 2);
//     }
// }

// int main() {
//     vector<int> inp;
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         int a;
//         cin >> a;
//         inp.push_back(a);
//     }

//     int target;
//     cin >> target;

//     findPairsWithSum(inp, target, 0, 1);
//     cout<<endl;
//     cout<<countSubsetsWithSum(inp, 0, target);
//     int a = 15;
//     char ele = char(a);
//     cout<<char(a);

//     return 0;
// }

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int index = 0) {
    if (index == n - 1) {
        return;  // Base case: If we have reached the end of the array, the sorting is done.
    }

    // Find the minimum element in the unsorted part of the array
    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the minimum element with the current element (arr[index])
    if (minIndex != index) {
        swap(arr[index], arr[minIndex]);
    }

    // Recursively sort the remaining unsorted part of the array
    selectionSort(arr, n, index + 1);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

