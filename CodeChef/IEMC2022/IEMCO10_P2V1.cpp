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


void solve(){
	vector<string> v;
	string s;
	while(getline(cin,s)){
		v.push_back(s);
	}
	int n,m;
	n=sz(v);
	int cnt=0;
	for(auto x:v[0]){
		if(x==' ')cnt++;
	}
	m=cnt+1;
	vector<vector<int>> arr(n,vector<int>(m,-1));
	vector<vector<int>> temp(n,vector<int>(m,0));
	int i=0;
	for(auto x:v){
		int j=0;
		for(auto y:x){
			if(y!=' '){
				arr[i][j]=(y-'0');
				j++;
			}
		}
		i++;
	}
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
	    int k=0;
	    int minrow=INT_MAX;
		for(int j=0;j<m;j++)
		{
		    
		    if(arr[i][j]<minrow)
		    {
		    	mp[arr[i][j]]++;
		        k=j;
		        minrow=arr[i][j];
		    }
		    
		}
		if(mp[arr[i][k]]>1)
			{
				cout<<"-1\n";
				return;
			}

		temp[i][k]=-1;
	}
	mp.clear();
	for(int i=0;i<n;i++)
	{
	    int k=0;
	    int maxrow=INT_MIN;
		for(int j=0;j<m;j++)
		{
		    if(arr[i][j]>maxrow)
		    {
		    	mp[arr[i][j]]++;
		        k=j;
		        maxrow=arr[i][j];
		    }
		    
		}
		if(mp[arr[i][k]]>1)
			{
				cout<<"-1\n";
				return;
			}

		temp[i][k]=-1;
	}
	mp.clear();
	for(int i=0;i<m;i++)
	{
	    int k=0;
	    int maxrow=INT_MIN;
		for(int j=0;j<n;j++)
		{
		    if(arr[j][i]>maxrow)
		    {
		    	mp[arr[j][i]]++;
		        k=j;
		        maxrow=arr[j][i];
		    }
		    
		}
		if(mp[arr[k][i]]>1)
			{
				cout<<"-1\n";
				return;
			}
		temp[k][i]=-1;
	}
	mp.clear();
	for(int i=0;i<m;i++)
	{
	    int k=0;
	    int minrow=INT_MAX;
		for(int j=0;j<n;j++)
		{
		    if(arr[j][i]<minrow)
		    {
		    	mp[arr[j][i]]++;
		        k=j;
		        minrow=arr[j][i];
		    }
		    
		}
		if(mp[arr[k][i]]>1)
			{
				cout<<"-1\n";
				return;
			}
		temp[k][i]=-1;
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        if(temp[i][j]==-1)count++;
	    }
	}
	cout<<count<<endl;
}

signed main(){    
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int TC = 1; 
    // cin >> TC;
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