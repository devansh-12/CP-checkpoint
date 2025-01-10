#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/* TYPES  */
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) {for (auto x : v) cout << x << " "; cout << endl; }

/* UTILS */
#define PI 3.1415926535897932384626433832795
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll LINF = 1e18;
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

vector<ll> dp(1e6+1,-1);

// ll minCoinsNeeded(int i,vector<int>& coins){
//     if(i==0){
//         return 0;
//     }
//     if(i<0){
//         return INT_MAX;
//     }
//     if(dp[i]!=-1){
//         return dp[i];
//     }
//     ll mini = INT_MAX;

//     for(auto coin:coins){
//         mini = min(mini,minCoinsNeeded(i-coin,coins)+1);
//     }

//     return dp[i]=mini;
// }

// void solve() {
//     int n,x;
//     cin>>n>>x;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     ll ans = minCoinsNeeded(x,coins);
//     if(ans>=INT_MAX){
//         cout<<-1<<endl;
//     }
//     else{
//         cout<< ans<<endl;
//     }
    
// }


void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=0;
    for(int i=1;i<=x;i++){
        ll mini = 1e9;
        for(auto coin:coins){
            
            if(i-coin>=0){
                mini = min(mini,1+dp[i-coin]);
            }
        }
        dp[i]=mini;
    }

    if(dp[x]>=1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[x]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}