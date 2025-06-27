#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<pair<long long,long long>> one , two; // currVal , currGCD
    int ans = n + 1, l = 0;
    for(int i=0;i<n;i++){
        long long twoGCD= two.empty()?0:two.top().second;
        long long oneGCD= one.empty()?0:one.top().second;
        if(one.empty()){
            one.push({arr[i],__gcd(arr[i],0LL)});
        }
        else{
            one.push({arr[i],__gcd(arr[i],oneGCD)});
        }
        oneGCD= one.empty()?0:one.top().second;

        while (__gcd(oneGCD,twoGCD)==1)
        {
            if(two.empty()){
                while(!one.empty()){
                    long long x = one.top().first;
                    one.pop();
                    long long currGCD = two.empty()?0:two.top().second;
                    two.push({x,__gcd(x,currGCD)});
                }
            }
            //cout
            ans = min(ans, i - l + 1);
            two.pop();
            l++;
            oneGCD = one.empty()?0:one.top().second;
            twoGCD = two.empty()?0:two.top().second;
        }
        
    }
    if (ans > n) ans = -1;
    cout<<ans<<endl;
    return 0; 
}