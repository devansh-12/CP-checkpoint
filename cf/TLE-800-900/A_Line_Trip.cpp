#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,f;
        cin>>n>>f;
        vector<int> arr(n+1);
        arr[0]=0;
        for(int i=1;i<n+1;i++){
            cin>>arr[i];
        }
        int maxi=0;
        for(int i=1;i<n+1;i++){
            maxi = max(maxi,arr[i]-arr[i-1]);
        }
        maxi = max((f-arr[n])*2,maxi);
        cout<<maxi<<endl;
    }
}