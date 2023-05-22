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
const int mxN=10;
vector<string> s(mxN);
int m,n;
vector<string> ans;
const string temp = "IEHOVA";

bool check(int i,int j){
	return (i<m&&i>=0&&j<n&&j>=0&&s[i][j]==temp[sz(ans)]);
}

bool check2(int i,int j){
	return (i<m&&i>=0&&j<n&&j>=0&&s[i][j]=='#');
}

void dfs(int i,int j){
	pr(ans);
	if(sz(ans)==6){
		if(check2(i-1,j)){
			ans.push_back("forth");
		}else if(check2(i,j-1)){
			ans.push_back("left");
		}else if(check2(i,j+1)){
			ans.push_back("right");
		}
		fr(x,7){
			cout<<ans[x];
			if(x<6){
				cout<<" ";
			}
		}
		return;
	}
	if(check(i-1,j)){
		ans.push_back("forth");
		dfs(i-1,j);
		ans.pop_back();
	}
	if(check(i,j-1)){
		ans.push_back("left");
		dfs(i,j-1);
		ans.pop_back();
	}
	if(check(i,j+1)){
		ans.push_back("right");
		dfs(i,j+1);
		ans.pop_back();
	}
}

void solve(){
	cin>>m>>n;
	fr(i,m){
		cin>>s[i];
	}
	int idx1,idx2;
	fr(i,m){
		fr(j,n){
			if(s[i][j]=='@'){
				idx1=i;
				idx2=j;
			}
		}
	}
	ans.clear();
	dfs(idx1,idx2);
}

signed main(){    
    setIO();
    
    pre();lli TC = 1; 
    cin >> TC;
    for(lli i = 1; i <= TC; i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
        if(i<TC)cout<<endl;
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