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

inline namespace FileIO {
	void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}


const int mxN=1e5+10;
lli n,k;
vi arr(mxN);
vector<vector<lli>> dp;
void pre(){
    
}
lli rec(int pos,int num){
	if(pos==n||num>35){
		return 0;
	}
	
	if(dp[pos][num]!=-1)return dp[pos][num];
	
	lli amount = (arr[pos]>>num);
	lli ans=-INF;
	ans=max(ans,amount-k+rec(pos+1,num));      // good key
	ans=max(ans,amount/2+rec(pos+1,num+1)); // bad key
	return dp[pos][num]=ans;
}
void solve(){
	
	cin>>n>>k;
	fr(i,n){cin>>arr[i];}
	
	dp=vector<vector<lli>> (n+1,vector<lli>(40,-1));
	lli ans=-INF;
	ans=max(ans,arr[0]-k+rec(1,0));      // good key
	ans=max(ans,(arr[0]>>1)+rec(1,1));   // bad key
	cout<<ans<<endl;
}

int main(){    
    setIO();
    ios_base::sync_with_stdio(false);cin.tie(0);  // FAST I/O
    
    pre();lli TC = 1; 
    cin >> TC;
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