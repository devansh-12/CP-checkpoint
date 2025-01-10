#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long  a,b,n;
        cin>>a>>b>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            b+=min(arr[i],a-1);
        }
        cout<<b<<endl;
    }
    return 0;
}