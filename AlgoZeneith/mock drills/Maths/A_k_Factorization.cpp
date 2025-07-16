#include<bits/stdc++.h>
using namespace std;

const int N =1e5;
vector<bool> prime(N+1,true);
vector<int> hp(N+1,0);
void seives(){
    prime[0]=prime[1]=false;
    
    for(int i=2;i<=N;i++){
        
        if(prime[i]==true){
            hp[i]=i;
            for(int j=i*2;j<=N;j+=i){
                prime[j]=false;
                hp[j]=i;
            }
        }

    }
}

int main(){
    int n,k;
    cin>>n>>k;
    seives();
    vector<int> f;
    int i=0;

    while(n>1 && i<k-1){
        int pf = hp[n];
        //cout<<pf<<"-";
        n/=pf;
        f.push_back(pf);
        i++;
    }

    if(n==1){
        cout<<-1<<endl;
    }

    else{
        f.push_back(n);
        for(int num:f){
            cout<<num<<" ";
        }
        cout<<endl;
    }


    return 0;
}