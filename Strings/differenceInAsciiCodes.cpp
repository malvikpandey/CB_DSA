#include<iostream>

using namespace std;

void diffAscii(char *str){
    int i=0;
    int j=1;

    while(str[j] != '\0'){
        if(i == 0){
            cout<<str[i]<<str[j]-str[i]<<str[j];
        }else{
            cout<<str[j]-str[i]<<str[j];
        }
        i++;
        j++;
    }
}

int main(){
    char str[1000];
    cin.getline(str, 1000);

    diffAscii(str);
    return 0;
}