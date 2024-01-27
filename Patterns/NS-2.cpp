#include<iostream>

using namespace std;

int main(){
    int n;
    int num = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        
        for(int k=0; k<=n-(n-i); k++){
            cout << num++;
        }
        num = 1;

        for(int j=1; j<n-i; j++){
            cout<<'*';
        }
        cout<<endl;
    }

        
    return 0;
}