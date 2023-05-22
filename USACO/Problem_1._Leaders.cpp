/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb emplace_back
#define MP make_pair
#define int long long
#define all(o) (o).begin(), (o).end()
#define fr(i,n) for(int i=0;i<n;++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x).size()
#define endl '\n'
typedef pair<int,int> pii;    typedef vector<int> vi;
typedef vector<pii> vii;      typedef vector<vi> graph; 
long long INF = 1e18;         long long MOD = 1e9+7;

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

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi arr(n);
	fr(i,n) {
		cin>>arr[i];
	}
	int hh=0,gg=0;
	vi h(n+1,0);
	vi g(n+1,0);
	fr(i,n) {
		h[i+1]=h[i];
		g[i+1]=g[i];
		if(s[i]=='H') {
			h[i+1]++;
			hh++;
		}else {
			g[i+1]++;
			gg++;
		}
	}
	set<pii> ans;
	int idx1=-1,idx2=-1;
	fr(i,n) {
		if(s[i]=='H') {
			int tot=h[arr[i]]-h[i];
			if(tot==hh) {
				if(idx1==-1) idx1=i;
			}
		}else {
			int tot=g[arr[i]]-g[i];
			if(tot==gg) {
				if(idx2==-1) idx2=i;
			}
		}
	}
	// pr(idx1,idx2);
	if(idx1!=-1&&idx2!=-1) {
		ans.insert({min(idx1,idx2),max(idx1,idx2)});
		fr(i,idx1) {
			if(s[i]=='G') {
				if(arr[i]-1>=idx1) {
					ans.insert({min(i,idx1),max(i,idx1)});
				}
			}
		}
		fr(i,idx2) {
			if(s[i]=='H') {
				if(arr[i]-1>=idx2) {
					ans.insert({min(i,idx2),max(i,idx2)});
				}
			}
		}
	}else if(idx1!=-1&&idx2==-1) {
		fr(i,idx1) {
			if(s[i]=='G') {
				if(arr[i]-1>=idx1) {
					ans.insert({min(i,idx1),max(i,idx1)});
				}
			}
		}
	}else if(idx1==-1&&idx2!=-1) {
		fr(i,idx2) {
			if(s[i]=='H') {
				if(arr[i]-1>=idx2) {
					ans.insert({min(i,idx2),max(i,idx2)});
				}
			}
		}
	}
	cout<<sz(ans)<<endl;
}