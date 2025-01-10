#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++){
        int target;
        cin>>target;
        int ans =-1;
        int low = 0,high= n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=target){
                ans = mid ;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(ans==-1){
            cout<<n+1<<endl;
        }
        else{cout<<ans+1<<endl;}

    }

    return 0;
}