#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void dupChar(string &str, int i){
    //base case
    if(str[i] == '\0'){
        return;
    }

    //recursive case
    if(str[i] == str[i+1]){
        int j = i+1;
        
        while(str[j] != '\0'){
            j++;
        }

        str.resize(j+1);

        while(j >= i+1){
            str[j+1] = str[j];
            j--;
        }
        
        str[i+1] = '*';
        dupChar(str, i+3);
    }else{
        dupChar(str, i+1);
    }

}

int main(){
    string str;
    cin>>str;
    dupChar(str, 0);
    cout<<str;
    return 0;
}