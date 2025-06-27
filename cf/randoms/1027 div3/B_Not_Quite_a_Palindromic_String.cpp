#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ones=0,zeroes;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        zeroes=n-ones;
        int diff = abs(zeroes-ones)/2;
        int mini = min(ones,zeroes);
        if(mini%2==1)mini--;
        if(diff%2==0 && k%2==1){
            cout<<"NO"<<endl;
        }
        else if(diff%2==1 && k%2==0){
            cout<<"NO"<<endl;
        }
        else if(diff>k){
            cout<<"NO"<<endl;
        }
        else if(diff+mini >= k ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
       

    }
    return 0;
}