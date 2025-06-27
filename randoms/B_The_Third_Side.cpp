#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long res = accumulate(a.begin(),a.end(),0LL);
        cout<<res-(n-1)<<endl;
    }
    return 0;
}