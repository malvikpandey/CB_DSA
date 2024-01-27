#include<iostream>
#include<cstring>

using namespace std;

void removeDupl(string str){
    string s = "";
    int n=str.size();

    for(int i=0; i<n; i++){
        if(i<n-1 && str[i] == str[i+1]){
            continue;
        }else{
            s += str[i];
        }
    }

    cout<<s<<endl;
}

int main(){
    string s;
    cin>>s;

    removeDupl(s);

    return 0;
}