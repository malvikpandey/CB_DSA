#include<iostream>
#include<cctype>

using namespace std;

int main(){
    char str[1000];
    cin.getline(str, 1000, '\n');

    for(int i=0; str[i]!='\0'; i++){
        if(i==0 && (str[i]>='A' && str[i]<='Z')){
            cout<<str[i];
        }else if(str[i]>='A' && str[i]<='Z'){
            cout<<endl;
            cout<<str[i];
        }else{
            cout<<str[i];
        }

        
    } 

	return 0;
}