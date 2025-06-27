#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0;
    map<int,int> m1;
    int ans = 0;
    while(r<n){
        if(m1.find(a[r])!=m1.end()){
            l=max(m1[a[r]]+1,l);
        }
        m1[a[r]]=r;
        ans = max(ans,r-l+1);
        r++;
       // cout<<ans<<" ";
    }
    cout<<ans<<"\n";
    return 0;
}