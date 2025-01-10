#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int pairs=0,l=0,r=n-1;
    while(l<r){
        if(arr[l]+arr[r]<=x){
            l++;r--;
            pairs++;
        }
        else if(arr[l]+arr[r]>x){
            r--;
        }

    }
    cout<<n-pairs<<endl;
    return 0;
}