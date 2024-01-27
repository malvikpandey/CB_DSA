#include<iostream>

using namespace std;

string oddEvenChar(string str){
    int i=0;
    while(str[i] != '\0'){
        if(i%2 == 0){
            str[i] += 1;
        }else{
            str[i] -= 1;
        }
        i++;

    }

    return str;
}

int main(){
    string str;
    cin>>str;

    cout<<oddEvenChar(str);
    return 0;
}



