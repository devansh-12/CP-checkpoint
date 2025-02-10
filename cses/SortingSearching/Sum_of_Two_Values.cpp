#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> m1 ;

    for(int i=0;i<n;i++){
        auto it = m1.find(x-a[i]);
        if(it!=m1.end()){
            cout<<it->second+1<<" "<<i+1<<endl;
            return 0;
        }
        m1[a[i]]=i;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}