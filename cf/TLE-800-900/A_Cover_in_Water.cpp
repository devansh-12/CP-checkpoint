#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool trio = false;
        int cnt=0,dotNum=0;
        vector<char> s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        for(int i=0;i<n;i++){

            if(s[i]=='.'){
                dotNum++;
                cnt++;
            }
            else{
                cnt=0;
            }

            if(cnt==3){
                trio = true;
                break;
            }
        }

        if(trio){
            cout<<2<<endl;

        }
        else{
            cout<<dotNum<<endl;
        }
    }
    return 0;
}