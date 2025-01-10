 #include<bits/stdc++.h>
 using namespace std;

 int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int> t ={1,-1};
        int x1,x2,y1,y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        set <pair<int,int>> s1,s2;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                s1.insert({ x1+a*t[i],y1+b*t[j]});
                s1.insert({ x1+b*t[i],y1+a*t[j]});
                s2.insert({ x2+a*t[i],y2+b*t[j]});
                s2.insert({ x2+b*t[i],y2+a*t[j]});
            }
        }
        int count = 0;
        for(auto e:s1){
            if(s2.find(e)!=s2.end()){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
 }