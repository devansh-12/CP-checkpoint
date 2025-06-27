#include<bits/stdc++.h>
using namespace std;

long long area(int minx,int miny,int maxx,int maxy,int n){
    long long h = maxx-minx+1;long long w = maxy-miny+1;
    if(h*w < n){
        return min(((w+1)*h),((h+1)*w));
    }
    return w*h;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> px(n),py(n),p(n);
       
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            p[i] = make_pair(x,y);
            px[i] = make_pair(x,i);
            py[i] = make_pair(y,i);
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
         sort(px.begin(),px.end());
        sort(py.begin(),py.end());
         long long  res = area(px[0].first,py[0].first,px[n-1].first,py[n-1].first,n) ;
       
        set<int> ends = {px[0].second,py[0].second,px[n-1].second,py[n-1].second};
        for(int ep:ends){
            int minx = px[0].second == ep ? px[1].first : px[0].first;
            int maxx = px[n-1].second == ep ? px[n-2].first : px[n-1].first;
            int miny = py[0].second == ep ? py[1].first : py[0].first;
            int maxy = py[n-1].second == ep ? py[n-2].first : py[n-1].first;
            res = min(res,area(minx,miny,maxx,maxy,n));
        }
        cout<<res<<endl;
    
    }
    
    return 0;
}