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
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
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


const int mxN=2550;
lli n,m;
vi arr(mxN),brr(mxN);
map<lli,vi> mp;
lli dp[mxN][mxN];
void pre(){
	
}
lli rec(int pos,int idx){
	if(pos==n){
		return 0;
	}
	
	if(dp[pos][idx]!=-1)return dp[pos][idx];
	
	lli ans=INF;
	int nxt=arr[pos];
	auto it=upper_bound(mp[nxt].begin(),mp[nxt].end(),idx);
	if(it!=mp[nxt].end()){
		ans=min(ans,abs(*it-idx)+rec(pos+1,*it));	
	}
	if(it!=mp[nxt].begin()){
		it--;
		ans=min(ans,abs(*it-idx)+rec(pos+1,*it));
	}
	return dp[pos][idx]=ans;
}
void solve(){
	mp.clear();
	cin>>n;
	arr.clear();
	arr.resize(n);
	fr(i,n){cin>>arr[i];}
	cin>>m;
	brr.clear();
	brr.resize(m);
	fr(i,m){
		cin>>brr[i];
		mp[brr[i]].push_back(i);
	}
	
	uniq(arr);
	n=sz(arr);
	if(n==1){
		cout<<0<<endl;
		return;
	}
	
	mset(dp,-1);
	lli ans=INF;
	for(auto x:mp[arr[0]]){
		ans=min(ans,rec(1,x));
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	pre();lli _t=1;cin>>_t;
	for(lli i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
