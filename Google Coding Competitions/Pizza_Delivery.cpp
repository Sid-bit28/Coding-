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

// North East West South
const int dx[4] = {-1, 0, 0, +1};
const int dy[4] = {0, +1, -1, 0};
int n,p,m,X,Y;
vector<int> a(4);
vector<char> b(4);
map<pii,int> mp,mp1;
int rec(int x,int y,int t,int mask){
	if(t==m+1){
		if((1<<(p+1))-1==mask){
			return 0;
		}else return -INF;
	}
	if(x>=n||x<0||y>=n&&y<0){
		return -INF;
	}
	int ans=-INF;
	fr(i,4){
		if(mp1.find({x,y})!=mp1.end()){
			if((mask&(1<<mp1[{x,y}]))==0){
				if(b[i]=='+'){
					ans=max(ans,a[i]+mp[{x,y}]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
				}else if(b[i]=='-'){
					ans=max(ans,-a[i]+mp[{x,y}]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
				}else if(b[i]=='*'){
					ans=max(ans,a[i]*(mp[{x,y}]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}])))));
				}else {
					ans=max(ans,(mp[{x,y}]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))))/a[i]);
				}
			}else {
				if(b[i]=='+'){
					ans=max(ans,a[i]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
				}else if(b[i]=='-'){
					ans=max(ans,-a[i]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
				}else if(b[i]=='*'){
					ans=max(ans,a[i]*(rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}])))));
				}else {
					ans=max(ans,(rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))))/a[i]);
				}
			}
		}else {
			if(b[i]=='+'){
				ans=max(ans,a[i]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
			}else if(b[i]=='-'){
				ans=max(ans,-a[i]+rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))));
			}else if(b[i]=='*'){
				ans=max(ans,a[i]*(rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}])))));
			}else {
				ans=max(ans,(rec(x+dx[i],y+dy[i],t+1,(mask|(1<<mp1[{x,y}]))))/a[i]);
			}
		}
		return ans;
	}
	void solve(){
		cin>>n>>p>>m>>X>>Y;
		fr(i,4){
			cin>>b[i]>>a[i];
		}
		fr(i,p){
			int a,b,c;
			cin>>a>>b>>c;
			mp[{a,b}]=c;
			mp1[{a,b}]=i;
		}
		cout<<rec(X,Y,0,0)<<endl;
	}

signed main(){    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int TC = 1; 
		cin >> TC;
		for(int i = 1; i <= TC; i++) {
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