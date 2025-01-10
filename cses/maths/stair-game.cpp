#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int sz;
        cin>>sz;
        int XOR_Total=0;
        for(int i=0;i<sz;i++){
            int x;
            cin>>x;

            if(i%2==1){
                XOR_Total^=x;
            }
        }
        if(XOR_Total!=0){
            cout<<"first"<<endl;
        }
        else{
            cout<<"second"<<endl;
        }
        
    }
    return 0;
}