#include"bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define F first
#define S second
#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (int)(x).size()
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

inline namespace FileIO {
	void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out");
	}
}


void pre(){
    
}
void solve(){
	int n,m;
	cin>>n>>m;
	vi arr(n);
	fr(i,n){cin>>arr[i];}
	
	vi naya(n,0);
	rep(i,1,n-1){
		if(arr[i]<arr[i-1]){
			naya[i]=arr[i-1]-arr[i];
		}
	}
	vi naya1(n,0);
	for(int i=n-1;i>0;i--){
		if(arr[i]>arr[i-1]){
			naya1[i-1]=arr[i]-arr[i-1];
		}
	}
	for(int i=n-2;i>=0;i--){
		naya1[i]+=naya1[i+1];
	}
	rep(i,1,n-1){
		naya[i]+=naya[i-1];
	}
	fr(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		if(a>b){
			cout<<naya1[b]-naya1[a]<<endl;
		}else {
			cout<<naya[b]-naya[a]<<endl;
		}
	}
}

signed main(){    
    setIO();
    
    pre();lli TC = 1; 
    // cin >> TC;
    for(lli i = 1; i <= TC; i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}


// Sometimes Read Here
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/