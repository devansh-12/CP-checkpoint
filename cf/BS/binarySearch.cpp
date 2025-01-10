#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<long long> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<k;i++){
        int item;
        cin>>item;
        int ans =-1;
        int low = 0,high= n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(v1[mid]==item){
                ans = mid;
                break;
            }
            else if(v1[mid]>item){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans==-1){
            cout<<"NO"<<endl;
        }
        else{cout<<"YES"<<endl;}

    }

    return 0;
}