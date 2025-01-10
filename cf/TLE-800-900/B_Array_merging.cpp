#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        ll  cnt=1,maxCnt=1;
        unordered_map<long long , long long> m1,m2;
        for(int i=0;i<n;i++){ //n-1
            if(i+1<n && a[i]==a[i+1]){
                cnt++;
            }
            else{
                m1[a[i]]=max(m1[a[i]],cnt);
                cnt=1;
            }
        }
        cnt=1;
        for(int i=0;i<n;i++){
            if(i+1<n && b[i]==b[i+1]){
                cnt++;
            }
            else{
                m2[b[i]]=max(m2[b[i]],cnt);
                cnt=1;
            }
        }
        for(auto &e:m1){
            m2[e.first] += e.second;
        }
        for(auto &e:m2){
            maxCnt = max(maxCnt,e.second);
        }
    
        cout<<maxCnt<<endl;
    }
}