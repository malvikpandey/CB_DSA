#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void nextGreaterEle(vector<int>& inp, int n){
    vector<int> out;
    stack<int> s;

    for(int i = 2*n-1; i>=0; i--){
        while(!s.empty() && s.top()<=inp[i%n]){
            s.pop();
        
        }

        if(i<n){
            if(s.empty()){
                out.push_back(-1);
            }else{
                out.push_back(s.top());
            }
        }
        
        s.push(inp[i%n]);
    }

    reverse(out.begin(), out.end());

    for(int i=0; i<out.size(); i++){
        cout<<out[i]<<" ";
    }


}

int main(){
    int n;
    cin>>n;

    vector<int> inp;

    for(int i=0; i<n; i++){
        int j;
        cin>>j;

        inp.push_back(j);
    }

    nextGreaterEle(inp, n);
    
    return 0;
}