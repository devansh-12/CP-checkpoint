#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    for(auto[f,s] : mp){

        for(int j=2*f;j<=mx;j+=f){
            if(mp.find(j)!=mp.end()){
                mp[j]++;
            }
        }

    }

    int cnt=0;
    for(auto [f,s]:mp){
        if(s==1)cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}