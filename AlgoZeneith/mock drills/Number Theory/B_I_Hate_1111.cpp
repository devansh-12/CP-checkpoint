#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        if(n>=1100){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=0;i<=9;i++){
            int num = n - i*111;
            if(num<0){break;}
            if(num%11==0){
                flag=true;
                break;
            }
        }

        if(flag)cout<<"YES";
        else cout<<"NO";
        cout<<endl;

    }
    return 0;
}