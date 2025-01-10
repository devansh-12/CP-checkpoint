#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> m1;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m1[x]++;
            
        }
        
        if(m1.size()>=3){
            cout<<"No"<<endl;
        }
        else if(m1.size()==1){
            cout<<"Yes"<<endl;
        }
        else{
            auto a = m1.begin();
            auto b = ++m1.begin();
            if(abs(a->second-b->second)<=1){
                //cout<<a->second<<b->second<<endl;
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}