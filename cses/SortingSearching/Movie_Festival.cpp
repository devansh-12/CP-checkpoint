#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    multimap<int,int> m1;//end time , start time
    int lastEnd =-1;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        m1.insert({y,x});
    }
    int cnt =0;
    for(auto it:m1){
        if(it.second>=lastEnd){
            lastEnd=it.first;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}