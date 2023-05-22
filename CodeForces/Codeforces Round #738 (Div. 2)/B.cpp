#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

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

const int mxN=110;
int n;
string s;
int dp[mxN][2];
// Red = 0  Blue = 1
int rec(int pos,int last){
	if(pos==n){
		return 0;
	}
	
	if(dp[pos][last]!=-1)return dp[pos][last];
	
	int ans=INF;
	if(s[pos]=='?'){
		if(last==0){
			ans=min({ans,1+rec(pos+1,0),rec(pos+1,1)});
		}else {
			ans=min({ans,1+rec(pos+1,1),rec(pos+1,0)});
		}
	}else {
		if(s[pos]=='R'){
			if(last==0){
				ans=min(ans,1+rec(pos+1,0));
			}else {
				ans=min(ans,rec(pos+1,0));
			}
		}else {
			if(last==0){
				ans=min(ans,rec(pos+1,1));
			}else {
				ans=min(ans,1+rec(pos+1,1));
			}
		}
	}
	return dp[pos][last]=ans;
}

void solve(){
	cin>>n>>s;
	memset(dp,-1,sizeof(dp));
	int ans=INF;
	if(s[0]=='?'){
		ans=min({ans,rec(1,0),rec(1,1)});
	}else {
		ans=min(ans,rec(1,(s[0]=='R'?0:1)));
	}
	pr(ans);
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}