#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> primes;
vector<set<int>> up;
vector<int> lp,hp;
void precompute(int N){
    isPrime.resize(N+1,true);
    lp.resize(N+1,1);hp.resize(N+1,1);

    isPrime[0]=isPrime[1]=false;

    for(int i=2;i<=N;i++){

        if(isPrime[i]==true){
            lp[i]=hp[i]=i;
            for(int j=2*i;j<=N;j+=i){
                
                isPrime[j]=false;
                
                if(lp[j]==1){
                    lp[j]=i;
                }
                hp[j]=i;
            }
        }

    }

}

set<int> primeset(int n){
    set<int> s1;
    while(n>1){

        int pf = hp[n];
        while(n%pf==0){
            n/=pf;
        }
        s1.insert(pf);
    }
    return s1;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    precompute(1e5);
    set<int> res;  
    for(int i=0;i<n;i++){
        set<int> temp = primeset(arr[i]);
        res.insert(temp.begin(), temp.end());
    }

    vector<int> sol;
    for(int i=1;i<=m;i++){
        set<int> temp = primeset(i);
        set<int> ans;
        set_intersection(
            temp.begin(),temp.end(),
            res.begin(),res.end(),
            inserter(ans,ans.begin())
        );


        if(ans.size()==0){
            sol.push_back(i);
        }
    }

    cout<<sol.size()<<endl;
    for(int a: sol){
        cout<<a<<endl;
    }


    return 0;
}