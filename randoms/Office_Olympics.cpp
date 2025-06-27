#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=n-1;i>=0;i-=2){
            if(i-1>=0){
                if(s[i-1]=='0' && s[i]=='0'){
                    cout<<"BOB"<<endl;
                    break;
                }
                if(s[i]=='1'){
                    cout<<"ALICE"<<endl;
                    break;
                }
                
            }
            else{
                if(s[i]=='1'){
                    cout<<"ALICE"<<endl;
                }
                else{
                    cout<<"BOB"<<endl;
                }
                break;
            }
        } 
    }
    return 0;
}