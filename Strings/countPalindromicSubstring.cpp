#include<iostream>
#include<cstring>

using namespace std;

int cPS(string str){
    int count = 0;
    bool flag = false;

    int n = str.size();

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			string subString = str.substr(i, j - i + 1);
			
            int k=0;
            int l=subString.size() - 1;

            while(k<=l){
                if(subString[k] != subString[l]){
                    flag = false;
                    break;
                }else{
                    flag = true;
                    
                }
                k++;
                l--;
    
            }


            if(flag == true){
                count++;
                flag = false;
            }

		}
    }

    return count;
}

int main(){
    string s;
    cin>>s;

    cout<<cPS(s);

    return 0;
}