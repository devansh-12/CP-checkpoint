#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll minSum =1 , cannot=minSum+1;
    if(arr[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(arr[i]>minSum+1){
            cannot = minSum+1;
            break;
        }
        else{
            minSum = max(minSum,arr[i]+minSum);
            cannot = minSum+1;
        }
    }
    cout<<cannot<<endl;
    return 0;
}