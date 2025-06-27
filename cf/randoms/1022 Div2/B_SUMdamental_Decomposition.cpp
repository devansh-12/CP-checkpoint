#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,n1,x;
        cin>>n>>x;
        int cnt=0;
        n1=x;
        while(x>0){
            x=(x&(x-1));
            cnt++;
        }
       // cout<<cnt;
        x=n1;
        int temp;
        if(x==0){
            if(n==1){
                cout<<-1;
            }
            else if(n==2){
                cout<<2;
            }
            else{
                cout<<(n-3)+6;
            }
        }
        else if(n==2 && x==1){
            cout<<5;
        }
        else if(n==2){
            if(cnt==1){
                cout<<x+2;
                //cout<<"hello";
            }
            else{
                cout<<x;
            }
        }
        else if((n-cnt)%2==0){
            temp=(n-cnt);
            cout<<x+temp;
        }
        else{
            temp=(n-cnt+1);
            cout<<x+temp;
        }
        cout<<"\n";

    }

    return 0;
}