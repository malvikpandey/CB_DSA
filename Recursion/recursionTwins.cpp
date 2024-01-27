#include<iostream>
#include<string>

using namespace std;
int countTwin = 0;

void cTwin(string str, int i){
    //base case
    if(i == str.size()-2){
        return;
    }

    //recursive case
    if(str[i] == str[i+2]){
        countTwin++;
    }

    cTwin(str, i+1);
}

int main(){
    string str;
    cin>>str;

    cTwin(str, 0);
    cout<<countTwin<<endl;
    return 0;
}