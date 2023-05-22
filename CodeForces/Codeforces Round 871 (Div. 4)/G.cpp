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

//nope:(
//hint:solution..
//link:https://www.youtube.com/watch?v=_k-w_5Ihiuo&ab_channel=Senior
const int mxN=1e6+10;
vt<int> ans(mxN,0);
void pre(){
     rep(i,1,mxN-1){
     	ans[i]=1LL*i*i;
     }
     int curr=1;
     rep(i,1,2023){
     	if(curr>mxN)break;
     	fr(j,i){
     		if(curr>mxN)break;
     		if(j&&j<i-1&&curr>(i-1)*2){
     			ans[curr]-=ans[curr-(i-1)*2];
     		}
     		if(curr+i<mxN){
     			ans[curr+i]+=ans[curr];
     		}
     		if(curr+i+1<mxN){
     			ans[curr+i+1]+=ans[curr];
     		}
     		curr++;
     	}
     }
}

void solve(){
	int n;
	cin>>n;
	cout<<ans[n]<<endl;
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