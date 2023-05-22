#include"bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
typedef long long lli;         typedef long double ld;
typedef pair<lli,lli> pii;     typedef vector<lli> vi;
typedef vector<pii> vii;       typedef vector<vi> graph;
const long long MOD=1000000007;const long long INF=1e18;
#ifndef SIDDARTH
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define pr(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#endif
lli binpow(lli b,lli p,lli mod=MOD){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}


const int mxN=1e5+10;
int n,k;
vector<char> arr(mxN);
lli dp[mxN][100][3];
void pre(){
    
}
//hoof = 0
//paper = 1
//scissors = 2
lli rec(int pos,int last,int num){
    if(pos==n){
        if(num>=0)return 0;
        return -INF;
    }
    
    if(dp[pos][num][last]!=-1){return dp[pos][num][last];}
    
    lli ans=0;
    if(arr[pos]=='H'){
        fr(i,3){
            if(i==1){
                ans=max(ans,1+rec(pos+1,i,num-((last==i)?0:1)));
            }else {
                ans=max(ans,rec(pos+1,i,num-((last==i)?0:1)));
            }
        }
    }else if(arr[pos]=='P'){
        fr(i,3){
            if(i==2){
                ans=max(ans,1+rec(pos+1,i,num-((last==i)?0:1)));
            }else {
                ans=max(ans,rec(pos+1,i,num-((last==i)?0:1)));
            }
        }
    }else {
        fr(i,3){
            if(i==0){
                ans=max(ans,1+rec(pos+1,i,num-((last==i)?0:1)));
            }else {
                ans=max(ans,rec(pos+1,i,num-((last==i)?0:1)));
            }
        }
    }
    return dp[pos][num][last]=ans;
}
void solve(){
    
    cin>>n;
    arr.resize(n);
    fr(i,n){cin>>arr[i];}
    
    mset(dp,-1);
    k=1;
    lli ans=0;
    fr(i,3){
        ans=max(ans,rec(0,i,k));
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);  // FAST I/O
    
    // freopen("hps.in","r",stdin);
    // freopen("hps.out","w",stdout);
    
    pre();lli TC = 1; 
    // cin >> TC;
    for(lli i = 1; i <= TC; i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    
    return 0;
}
