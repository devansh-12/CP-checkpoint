#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> m1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m1.insert(-x);

    }

    for(int i=0;i<m;i++){
        int x;
        cin>>x;

        auto it = m1.lower_bound(-x);
        if(it!=m1.end()){
            cout<<-*(it)<<endl;
            m1.erase(it);
        }
        else{
            cout<<-1<<endl;
        }

    }
    
    return 0;
}

