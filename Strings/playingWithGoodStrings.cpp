#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int playGD(string str){
    int count = 0;
    int maxLength = 0;

	for (char ch :  str) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
			maxLength = max(maxLength, count);
		} else {
			count = 0;
		}
	}
            
    return maxLength;
            
}
       





int main(){
    string str;
    cin>>str;

    cout << playGD(str) << endl;

    return 0;
}