#include<bits/stdc++.h>
using namespace std;   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        vector<long long> a;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        long long cnt=0;
        long long sum = accumulate(a.begin(),a.end(),0);
        sort(a.begin(),a.end());
        long long sum1 = sum - y,sum2 = sum - x;
        long long ans1=0,ans2=0;
        int l=0,r=n-1;
        while(l<r){
            if(a[l]+a[r]<=sum2){
                ans1+=(r-l);
                l++;
            }
            else{
                r--;
            }
        }
        l=0,r=n-1;
        while(l<r){
            if(a[l]+a[r]<sum1){
                ans2+=(r-l);
                l++;

            }
            else{
                r--;
            }
        }
        cout<<(ans1-ans2)<<endl;
    }
    return 0;
}
