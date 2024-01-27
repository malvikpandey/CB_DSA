#include<iostream>

using namespace std;

void sumTA(int *arr, int *brr, int n, int m){
    int c = max(m, n);
    int ans[c]={};
    int i=m-1;
    int j=n-1;
    int k=c-1;
    int carry=0;

    while(k>=0){
        int sum = carry;
        if(i>=0){
            sum += brr[i];
        }

        if(j>=0){
            sum += arr[j];
        }
        
        carry = sum/10;
        ans[k] = sum%10;

        k--;
        j--;
        i--;
    }

    if(carry>0){
        cout<<carry<<", ";
    }

    for(int i=0; i<=c; i++){
        if(i != c){
            cout<<ans[i]<<", ";
        }else{
            cout<<"END";
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n]={};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;

    int brr[m]={};
    for(int i=0; i<m; i++){
        cin>>brr[i];
    }

    sumTA(arr, brr, n, m);
    return 0;
}