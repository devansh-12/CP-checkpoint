#include<bits/stdc++.h>
using namespace std;   

typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        //long long asum = accumulate(a.begin(),a.end(),0);

        long long res=0;
        priority_queue<pii , vector<pii>,greater<pii>> minHeap;
        for(int i=0;i<n;i++){
            minHeap.push({b[i]-a[i],i});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        long long mini = LONG_LONG_MAX;
        while(!minHeap.empty()){
            auto it = minHeap.top();
            if(mini>b[it.second]){
                mini = b[it.second];
            }
            //res+=b[it.second];
            a[it.second]=-1;
            minHeap.pop();
        }
        for()
        cout<<res<<endl;
    }
    return 0;
}
