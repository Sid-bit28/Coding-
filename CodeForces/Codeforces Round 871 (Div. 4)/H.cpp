#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define F first 
#define S second
#define pb push_back
#define vt vector
#define all(o) (o).begin(), (o).end()
#define fr(i,n) for(int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
const long long MOD = 1000000007;
using pii = pair<int,int>;    using vii = vt<pii>;
#ifndef ONLINE_JUDGE
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
int binpow(int b, int p, int mod){int ans = 1;b %= mod;for(; p ; p>>=1){if(p & 1)ans = ans * b % mod;b = b * b % mod;}return ans;}

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */
struct mi {
    int v; explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a;
}
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
istream& operator>>(istream&i,mi&a){i>>a.v;return i;}
ostream& operator<<(ostream&o,const mi&a){o<<a.v;return o;}

//yupppppppp
void pre(){
	
}

void solve(){ 
     int n,k;
     cin>>n>>k;
     vt<int> arr(n);
     fr(i,n){
     	cin>>arr[i];
     }
     vt<vt<int>> dp(n,vt<int>((1<<6),-1));
     auto rec=[&](auto rec,int pos,int val)->int{
     	if(pos==n){
     		if(__builtin_popcount(val)==k){
     			return 1;
     		}else return 0;
     	}
     	if(dp[pos][val]!=-1){
     		return dp[pos][val];
     	}
     	mi ans=0;
     	ans+=rec(rec,pos+1,val);
     	ans+=rec(rec,pos+1,val&arr[pos]);
     	return dp[pos][val]=(int)ans;
     };
     mi ans=0;
     for(int i=0;i<n;i++){
     	ans+=rec(rec,i+1,arr[i]);
     }
     cout<<ans<<endl;
}

signed main(){
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
     pre();int TC = 1;
     cin >> TC;
     rep(i, 1, TC){
          // cout<<"Case #"<<i<<": ";
          solve();
     }
}