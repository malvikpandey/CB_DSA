#include<iostream>
#include<cstring>

using namespace std;

char maxFreq(string str){
    int count[26] = {};
    int maxLen = 0;

    for(char k : str){
        count[k-'a']++;  
    }

    int n = 0;

    for(int i=0; i<26; i++){
        if(count[i]>maxLen){
            maxLen = count[i];
            n = i;
        }
    }

    return 'a' + n;

}

int main(){
    string s;
    cin>>s;

    cout<<maxFreq(s);

    return 0;
}