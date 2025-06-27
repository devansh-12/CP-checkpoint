#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long res ;
        if(n%2==0){
            res = ((n+1)/2)*(n);
        }
        else{
            res = ((n+1)/2)*(n-1);
        }
        //cout<<res<<" ";
        cout<<res/2+1<<endl;
    }
    return 0;
}

mmi