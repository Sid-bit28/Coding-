#include<bits/stdc++.h>
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (int)(x).size()
#define int long long
#define endl '\n'
typedef pair<int,int> pii;    typedef vector<int> vi;
typedef vector<pii> vii;      typedef vector<vi> graph;
long long MOD=1000000007;     long long INF=1e18;
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
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

bool ok=true;
set<pair<pii,string>> vis;
int ans;
void pre(){
	
}

void solve(){
	int n,m,a,b,c,d;
	string s;
	cin>>n>>m>>a>>b>>c>>d>>s;
	
	auto dfs = [&](auto dfs, int x, int y, string dd) -> int {
		if(x==c&&y==d){
			return 1;
		}
		if(vis.count({{x,y},dd})){
			ok=false;
			return 0;
		}
		vis.insert({{x,y},dd});
		if(x==n&&y==m&&dd=="DR"){
			ans++;
			return dfs(dfs, x, y, "UL");
		}
		if(x==n&&y==1&&dd=="DL"){
			ans++;
			return dfs(dfs, x, y, "UR");
		}
		if(x==1&&y==m&&dd=="UR"){
			ans++;
			return dfs(dfs, x, y, "DL");
		}
		if(x==1&&y==1&&dd=="UL"){
			ans++;
			return dfs(dfs, x, y, "DR");
		}
		if(x==n&&dd=="DL"){
			ans++;
			return dfs(dfs, x, y, "UL");
		}
		if(x==n&&dd=="DR"){
			ans++;
			return dfs(dfs, x, y, "UR");
		}
		if(x==1&&dd=="UL"){
			ans++;
			return dfs(dfs, x, y, "DL");
		}
		if(x==1&&dd=="UR"){
			ans++;
			return dfs(dfs, x, y, "DR");
		}
		if(y==m&&dd=="UR"){
			ans++;
			return dfs(dfs, x, y, "UL");
		}
		if(y==m&&dd=="DR"){
			ans++;
			return dfs(dfs, x, y, "DL");
		}
		if(y==1&&dd=="UL"){
			ans++;
			return dfs(dfs, x, y, "UR");
		}
		if(y==1&&dd=="DL"){
			ans++;
			return dfs(dfs, x, y, "DR");
		}
		if(dd=="DL"){
			return dfs(dfs, x+1, y-1, dd);
		}
		if(dd=="DR"){
			return dfs(dfs, x+1, y+1, dd);
		}
		if(dd=="UL"){
			return dfs(dfs, x-1, y-1, dd);
		}
		return dfs(dfs, x-1, y+1, dd);
	};
	ans=0;
	dfs(dfs, a, b, s);
	if(ok==false)ans=-1;
	cout<<ans<<endl;
	vis.clear();
	ok=true;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  // freopen("innn.txt","r",stdin);
  // freopen("out.txt","w",stdout);
	pre();int _t=1;cin>>_t;
	for(int i=1;i<=_t;i++){
    // cout<<"Case #"<<i<<": ";
		solve();
	}
}