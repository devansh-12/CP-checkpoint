#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;

    while(t--)
        {
            int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        if(n==1){
            if(a[0]>b[0]){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
            continue;
        }
        sort(b.begin(),b.end(),greater<int>());
        sort(a.begin(),a.end(),greater<int>());
        int i=0,j=0,flag=0;
        ll ans = 1;
        while(i<=n && j<n ){
            if(j>i){
                break;
            }
            while(i<n && a[i]>b[j]){
                i++;
            }
            ans = (ans * (i-j))%mod ;
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}