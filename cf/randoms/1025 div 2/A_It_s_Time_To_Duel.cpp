#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v1(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        int ones = accumulate(v1.begin(),v1.end(),0);
        if(ones >= n){
            cout<<"YES"<<"\n";
            continue;
        }
        int i=0;
        for(i=1;i<n;i++){

            if(v1[i]==0 && v1[i-1]==0){
                cout<<"YES"<<"\n";
            break;
            }

        }
        if(i==n)
        cout<<"NO"<<"\n";
    }
    
    
    return 0;
}