#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    int m;
    cin>>m;
    cin>>n;

    int arr[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int minR[m] = {};
    
    for(int i=0; i<m; i++){
        int mini = INT_MAX;

        for(int j=0; j<n; j++){
            mini = min(mini, arr[i][j]);
        }
        minR[i] = mini;
    }

    int maxC[n] = {};

    for(int i=0; i<n; i++){
        int maxc = INT_MIN;
        for(int j=0; j<m; j++){
        maxc = max(maxc, arr[j][i]);
        }
        maxC[i] = maxc;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(minR[i] == maxC[j]){
                cout<<minR[i]<<endl;
                break;
            }
        }
    }
    return 0;
}