#include<iostream>
#include<algorithm>

using namespace std;

void cirSubSum(int *arr, int n){    
    int x = arr[0];
    int y = arr[0];
    int sum = arr[0];

	int maxSum = x;
    int minSum = y;

	for (int i = 1; i < n; i++) {
        x= max(arr[i], x+arr[i]);
        maxSum = max(maxSum, x);

        y=min(arr[i], y+arr[i]);
        minSum = min(minSum, y);

        sum += arr[i];   
	}
    
    if(maxSum>sum){
        cout<<maxSum<<" ";
    }else{
        cout<<max(maxSum, sum-minSum);
    }

}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cirSubSum(arr, n);
    return 0;
}