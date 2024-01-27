#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void deleteMidEle(int n){
    stack<int> s;
    vector<int> res;

    for(int i=0; i < n; i++){
        int inp;
        cin>>inp;
        s.push(inp);
    }

    //cout<<s.top();

    int repetetion = 0;

    while(repetetion < n){
        if(repetetion == n/2){
            s.pop();
            repetetion++;
            //cout<<"@";
        } else {
            res.push_back(s.top());
            s.pop();
            repetetion++;
            //cout<<"$";
        }
    }

    for(int i : res){
        cout<<i<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    deleteMidEle(n);

    return 0;
}