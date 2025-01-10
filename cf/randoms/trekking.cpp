#include<bits/stdc++.h>
using namespace std;   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        vector<long long> a,q;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            q.push_back(x);
        }
        if(k==n){
            for(int i=0;i<m;i++){
                cout<<1;
            }
            cout<<endl;
            continue;
        }
        if(n-k>1){
            for(int i=0;i<m;i++){
                cout<<0;
            }
            cout<<endl;
            continue;
        }
        long long sum1 = (k+2)*(k+1)/2;
        long long sum2 = accumulate(q.begin(),q.end(),0);
        long long dif = sum1-sum2;
        //cout<<dif;
        for(int i=1;i<=m;i++){
            if(dif==i){
                cout<<1;
            }
            else{cout<<0;}
        }
        cout<<endl;

    }
    return 0;
}
