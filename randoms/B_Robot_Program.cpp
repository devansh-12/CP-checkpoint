#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,x,k;
        cin>>n>>x>>k;
        string s;
        cin>>s;
        long long t1=k+1,t2=k+1,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                cnt--;
            }
            else{
                cnt++;
            }

            if(cnt==x*-1){
                t1=i+1;
                break;
            }
        }

        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt==0){
                t2=i+1;
                break;
            }
        }

        long long ans =0;
        if(k-t1>=0){
            ans+=1;
            k-=t1;
            ans+=(k/t2);
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
        
    }
    return 0;
}