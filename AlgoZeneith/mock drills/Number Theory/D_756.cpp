#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<bool> prime(N+1,true);
vector<int> lp(N+1,1),hp(N+1,1);
map<int,int> primes;
void seives(){
    prime[0]=prime[1]=false;

    for(int i=2;i<=N;i++){

        if(prime[i]==true)
        {
            lp[i]=hp[i]=i;
            primes[i]=0;
            for(int j=2*i;j<=N;j+=i){
                if(lp[j]==1){
                    lp[j]=i;
                }
                hp[j]=i;
                prime[j]=false;
            }
        }
    }
}

int cntPowers(int num){
    int cnt=0;
    for(auto e:primes){
        if(e.second >= num)cnt++;
    }
    return cnt;
}

int main(){
    
    int n;
    cin>>n;

    int res = 0;
    seives();
    for(int i=1;i<=n;i++){
        int temp =i;
        while(temp > 1){
            int pf = hp[temp];
            while(temp % pf == 0){
                temp /= pf;
                primes[pf]++;
            }
        }
    }

    res += cntPowers(14) * (cntPowers(4)-1);
    res += cntPowers(74);
    res += cntPowers(24)*(cntPowers(2)-1);
    
    res += cntPowers(4)*(cntPowers(4)-1)*(cntPowers(2)-2)/2;
    cout<<res<<endl;
    return 0;
}