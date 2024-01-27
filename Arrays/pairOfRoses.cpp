#include<iostream>
#include<algorithm>

using namespace std;

void pairOfRoses(int nOfRoses, int *priceOfRoses, int money){
    
    sort(priceOfRoses, priceOfRoses+nOfRoses);
    
    int left=0;
    int right=nOfRoses-1;
    int min;
    int max;

    while(left<right){
        if(priceOfRoses[left] + priceOfRoses[right] == money){
            min = left;
            max = right;
            left++;
            right--;
        }else if(priceOfRoses[left] + priceOfRoses[right] > money){
            right--;
        }else{
            left++;
        }
    }

    cout<<"Deepak should buy roses whose prices are "<<priceOfRoses[min]<<" and "<<priceOfRoses[max]<<"."<<endl;
}

int main(){
    int n;
    cin>>n;

    while(n>0){
        int nOfRoses;
        cin>> nOfRoses;
        int priceOfRoses[nOfRoses];

        for(int i=0; i<nOfRoses; i++){
            cin>>priceOfRoses[i];
        }

        int money;
        cin>>money;

        pairOfRoses(nOfRoses, priceOfRoses, money);

        n--;
    }
    return 0;
}