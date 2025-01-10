#include<bits/stdc++.h>
using namespace std;

int main(){
    //system("clear");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int sz;
    cin>>sz;
    vector<int> dp(n+1,0);
    //dp[0]=0;
    vector<int> moves;
    for(int i=0;i<sz;i++){
        int x;
        cin>>x;
        moves.push_back(x);
    }
    for(int i=1;i<=n;i++){
        //int res=0;
        for(int j=0;j<sz;j++){
            if(i-moves[j]>=0 && dp[i-moves[j]]==0){
                //res=1;
                dp[i]=1;
            }
        }
        
        if(dp[i]==1)
        {
            cout<<"W";
        }
        else{cout<<"L";}
    }
    cout<<endl;
    return 0;
}