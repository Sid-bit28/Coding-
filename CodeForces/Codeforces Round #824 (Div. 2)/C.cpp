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

struct UnionFind {
	int n, set_size, *parent, *rank;
	UnionFind(){}
	UnionFind(int a){
		n = set_size = a;
		parent = new int[n+1];
		rank = new int[n+1];
		for(int i = 1; i <= n; ++i)
			parent[i] = i, rank[i] = 1;
	}
	int find(int x){
		if(x != parent[x])return parent[x] = find(parent[x]);
		return x;
	}
	void merge(int x,int y){
		int xroot = find(x), yroot = find(y);
		if(xroot != yroot){
			if(rank[xroot] >= rank[yroot]){
				parent[yroot] = xroot;
				rank[xroot] += rank[yroot];
			}else {
				parent[xroot] = yroot;
				rank[yroot] += rank[xroot];
			}
			set_size -= 1;
		}
	}
	void reset(){
		set_size = n; for(int i = 1; i < n; i++)parent[i] = i,rank[i] = 1;
	}
	int size() {return set_size;}
	void print() {for(int i = 1; i <= n; i++) cout << i << "-->" << parent[i] << endl;}
};

void pre(){

}

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	UnionFind uf(30);
	set<char> ss;
	fr(i,26){
		ss.insert('a'+i);
	}
	map<char,char> mp;
	fr(i,n){
		if(mp.find(s[i])==mp.end()){
			for(auto x:ss){
				if(uf.find(x-'a'+1)!=uf.find(s[i]-'a'+1)){
					uf.merge(s[i]-'a'+1,x-'a'+1);ss.erase(x);mp[s[i]]=x;
					break;
				}
			}
		}
	}
	fr(i,n){
		if(mp.find(s[i])==mp.end()){
			cout<<*ss.begin();
		}else cout<<mp[s[i]];
	}
	cout<<endl;
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
        // cout<<"Case #"<<i<<": ";
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