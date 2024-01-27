#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    int num;
    int m = n/2 + 1 ;

    while (i <= n)
    {
        
        if(i <= m){
            num = i;

            //spaces
            for(int j=1; j<= n-2*i+1; j++){
                cout<<" "<<" ";
            }

            //numbers
            for(int j=1; j<=i; j++){
                cout<<num--<<" ";
            }

            //spaces
            for(int j=1; j<=n-2*(m-i)-2; j++){
                cout<<" "<<" ";
            }

            //numbers in inc. order
            for(int j=1; j<=i+1; j++){
                if(i == 1){
                    continue;
                }else if(num <= 0){
                    num++;
                }else{
                    cout<<num++<<" ";
                }
            }
        }else{
            num =n-i+1;

            //spaces
            for(int j=1; j<=2*(i-m); j++){
                cout<<" "<<" ";
            }

            //numbers
            for(int j=1; j<= n-i+1; j++){
                cout<<num--<<" ";
            }

            //spaces
            for(int j=1; j<=2*(n-i)-1; j++){
                cout<<" "<<" ";
            }
            //numbers
            for(int j=1; j<=n-i+2; j++){
                if(i == n){
                    continue;
                }else if(num <= 0){
                    num++;
                }else{
                    cout<<num++<<" ";
                }
                
            }
            
        } 
        cout << endl;
        i++;
    }
    return 0;
}