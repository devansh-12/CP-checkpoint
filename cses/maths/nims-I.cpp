#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int sz;
        cin>>sz;
        int finalXOR = 0;
        for(int i=0;i<sz;i++){
            int x;
            cin>>x;
            finalXOR ^= x;
        }
        if(finalXOR!=0){
            cout<<"first"<<endl;
        }
        else{
            cout<<"second"<<endl;
        }
    }
    return 0;
}