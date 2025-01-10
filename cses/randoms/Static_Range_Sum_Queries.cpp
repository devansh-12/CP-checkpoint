#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> arr(n+1);
    arr[0]=0;
    for(int i=1;i<n+1;i++){
        int x;
        cin>>x;
        arr[i]=arr[i-1]+x;
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<endl;
    }

    return 0;
}