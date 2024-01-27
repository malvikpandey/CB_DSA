#include<iostream>
#include<cstring>
#include<cctype>


using namespace std;

void strComp(string str){
    string res = "";

    for(int i=0; i<str.size(); i++){

        int count = 1;
        for(int j=i; j<str.size() && str[j] == str[j+1]; j++){
            count++;
            i++;
        }

        if(count>1){
            res += str[i];
            res += to_string(count);
        }else{
            res += str[i];
        }

        count = 0;
    }

    cout<<res<<endl;
}

int main(){
    string str;
    cin>>str;

    strComp(str);

    return 0;
}