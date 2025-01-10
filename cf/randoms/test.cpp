#include<bits/stdc++.h>
using namespace std;   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a, b;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=0; i<n;i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        b.push_back(0);
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        int l=0,r=1;
        int sum=0;
        while(r<=n){
            if(a[l]-b[r]>0){
                sum+=a[l]-b[r];
            }
            l++;r++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
