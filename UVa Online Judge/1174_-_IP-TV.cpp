#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,pair<int,int>>> mp(m);
		map<string,int> v;
		int val=1;
		for(int i=0;i<m;i++){
			string a,b;cin>>a>>b;
			int x;cin>>x;
			if(v.find(a)==v.end()){
				v[a]=val++;
			}
			if(v.find(b)==v.end()){
				v[b]=val++;
			}
			mp[i].first=x;mp[i].second.first=v[a];mp[i].second.second=v[b];
		}
		sort(all(mp));
		UnionFind uf(n+1);
		int ans=0;
		for(auto x:mp){
			if(uf.find(x.second.first)!=uf.find(x.second.second)){
				uf.merge(x.second.first,x.second.second);
				ans+=x.first;
			}
		}
		cout<<ans<<endl;
		if(tt){
			cout<<endl;
		}
	}
}