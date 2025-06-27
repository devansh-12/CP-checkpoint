#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> starts(n+1,0);
    vector<int> times(n+1,0);
    long long time=0;
    for(int i=0;i<m;i++){
        int id,entryTime;
        string s;
        cin>>id>>s>>entryTime;
        if(s=="Enters"){
            starts[id]=entryTime;
        }
        else{
            times[id]+=entryTime-starts[id];
        }

    }
    for(int i=0;i<n+1;i++){{
        cout<<times[i]<<" ";
    }
    return 0;
}