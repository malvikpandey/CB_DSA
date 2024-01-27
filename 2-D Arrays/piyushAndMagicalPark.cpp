#include<iostream>

using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;

    char cArr[n][n];

    int k;
    int s;
    cin>>k>>s;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cArr[i][j];
        }
    }

    for(int i=0; i<n && s>=k; i++){
        for(int j=0; j<m && s>=k; j++){
            if(j != 0){
                s--;
            }

            if(cArr[i][j] == '.'){
                s -= 2;
            }else if(cArr[i][j] == '*'){
                s += 5;
            }else{
                break;
            }
            
        }
    }

    if(s >= k){
        cout<<"Yes"<<endl;
        cout<<s;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}