#include<iostream>
#include<string>

using namespace std;

bool obS = false;

void obdStr(string &str, int i){
    //base case
    if(str[i] == '\0'){
        return;
    }

    //recursive case
    if(str[i] == 'a'){
        if(str[i+1] == 'b' && str[i+2] == 'b'){
            if(str[i+3] == 'a'){
                obS = true;
                obdStr(str, i+3);
            }else{
                if(str[i+3] == '\0'){
                    obS = true;
                }else{
                    obdStr(str, i+2);
                }
            }
        }else{
            obdStr(str, i+1);
        }
    }else{
        obS = false;
    }

    
}

int main(){
    string str;
    cin>>str;
    obdStr(str, 0);
    cout<<boolalpha<<obS;
    return 0;
}