#include<iostream>
using namespace std;

void printPattern(int n){
    int j=1;
    int sumArr[n] = {};
    sumArr[0]=1;
    while(j<=n){
        // for(int i=1; i<=n-j; i++){
        //     cout<<" "<<"\t";
        // }

        
        for(int i=1; i<=j; i++){
            if(i==1 || i==j){
                cout<<"1"<<"\t\t";
            }else{
                cout<<sumArr[i-2] + sumArr[i-1]<<"\t\t";
            }
        }

        for(int i=j; i>0; i--){
            if(i+1 == j){
                sumArr[i]  = 1;
            }else{
                sumArr[i] = sumArr[i] + sumArr[i-1];
            }

        }
        cout<<endl;
        j++;
    }
}

int main(){
    int n;
    cin>>n;
    printPattern(n);

    return 0;
}