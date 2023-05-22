#include <bits/stdc++.h>
using namespace std;
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
#define sz(x) (int)(x).size()
#define endl '\n'

template<class T> using v = vector<T>;
using vi = v<int>;        using pii = pair<int,int>;
using vii = v<pii>;       using graph = v<vi>;
const int MOD = 1e9+7;    const int INF = 1e18;

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

/**
 * Source: KACTL
 * Time: O(N)
 * Description: \texttt{lps[i]} is length of the longest proper suffix 
 	* of the i-th prefix of s that is a prefix of s
 * Verification: https://open.kattis.com/problems/stringmatching
 */

vi kmp(string s) {
	int N = sz(s); vi lps(N+1); lps[0] = -1;
	int i = 0, j = -1;
	while(i < N){
		while(j != -1 && s[i] != s[j])j = lps[j];
		i++;j++;lps[i] = j;
	}
	return lps;
}
vi getOc(string a, string b) { // find occurrences of a in b
	vi f = kmp(a+"@"+b), ret;
	rep(i,sz(a),sz(b))if (f[i+sz(a)+1] == sz(a)) 
		ret.EB(i-sz(a));
	return ret;
}
void solve(){
	int n;string s;
	cin>>n>>s;
	vi a=kmp(s);
	if(n%(n-a[n])){
		cout<<s<<endl;
	}else {
		cout<<s.substr(0,n-a[n])<<endl;
	}
}

signed main(){    
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int TC = 1; 
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout<<"Case #"<<i<<": ";
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