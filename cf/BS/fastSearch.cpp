#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    sort(arr.begin(),arr.end());

    for(int i=0;i<k;i++){
        int k1,k2;
        cin>>k1>>k2;

        int ans1=-1,ans2 =-1;
        int low = 0,high= n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<k1){
                ans1=mid;
                low=mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 0,high= n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<=k2){
                ans2 = mid;
                low=mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        cout<<ans2-ans1<<" ";

    }

    return 0;
}