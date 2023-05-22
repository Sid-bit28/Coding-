#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000")
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define fr(i,n) for(int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define rsz resize
#define sz(x) (int)(x).size()
#define endl '\n'
template<class T> using v = vector<T>;
using vi = v<int>;        using pii = pair<int,int>;
using vii = v<pii>;       using graph = v<vi>;
const int MOD = 1e9+7;    const int INF = 1e18;
typedef long double ld;   const ld EPS = 1e-9;
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
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

int n,q;
graph g;
void pre(){

}
void bfs(int root,vi &dis){
	dis[root]=0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int nn=q.front();q.pop();
		for(auto cc:g[nn]){
			if(dis[cc]>dis[nn]+1){
				dis[cc]=dis[nn]+1;
				q.push(cc);
			}
		}
	}
}
void solve(){
	cin>>n>>q;
	g.clear();
	g.resize(n+1);
	fr(i,n-1){
		int a,b;cin>>a>>b;
		g[a].EB(b);
		g[b].EB(a);
	}
	vi dis(n+1,INF);
	bfs(1,dis);
	map<int,int> mp;
	rep(i,1,n)mp[dis[i]]++;
	fr(i,q){
		int a;cin>>a;
	}
	int ans=0;
	for(auto x:mp){
		if(q>=x.S){
			q-=x.S;ans+=x.S;
		}else break;
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // cout<<fixed<<setprecision(15);
    // clock_t begin = clock();
    pre();int TC = 1; 
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    // clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
    return 0;
}

// Sometimes Read Here
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/