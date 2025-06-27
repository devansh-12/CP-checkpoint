#include<bits/stdc++.h>
using namespace std;

const int sz = 1e4;
vector<bool> isPrime(sz+1,true);

int main(){
    int t;
    cin>>t;

    vector<bool> isPrime(sz+1,true);
    isPrime[0]=isPrime[1]=false;
    vector<int> primes;
    for(int i=2;i<=sz;i++){
        if(isPrime[i]){
        primes.push_back(i);
        for(int j=i*2;j<=sz;j+=i){
            isPrime[j]=false;
        }
    }
    }
    while(t--){
        int n;
        cin>>n;
        int num=-1;
        vector<int> a(n);
        //map<int,int> m1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            //m1[a[i]]++;
        }
        bool allSame = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            cout << "No\n";
            continue;
        }
        for(auto e:primes){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(a[i]%e==0){
                    cnt++;
                }
            }
            
            if(cnt==n){
                int j=0;
                int cnt1;
                do{
                    cnt1=0;
                    j++;
                    for(int i=0;i<n;i++){
                        if(a[i]%(int)pow(e,j)==0){
                            cnt1++;
                        }
                    }
                }while(cnt1==n);
                num = (int)pow(e,j);
                break;
            }
            else if(cnt>=n/2){
                num=e;
                break;
            }
        }
        if(num==-1){
            cout<<"No"<<endl;
            continue;
        }
        else{
            cout<<"Yes"<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%num==0){
                cout<<1;
            }
            else{
                cout<<2;
            }
            cout<<" ";
        }
        cout<<endl;
        }

    }
    return 0;
}