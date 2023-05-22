#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

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

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	UnionFind uf1(n),uf2(n);
	for(int i=0;i<x;i++){
		int a,b;
		cin>>a>>b;
		uf1.merge(a,b);
	}
	for(int i=0;i<y;i++){
		int a,b;
		cin>>a>>b;
		uf2.merge(a,b);
	}
	vector<pair<int,int>> ans;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(uf1.find(i)!=uf1.find(j) && uf2.find(i)!=uf2.find(j)){
				ans.push_back({i,j});
				uf1.merge(i,j);
				uf2.merge(i,j);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  	int t = 1;
  	// cin >> t;
  	while(t--) {
  		solve();
  	}
    return 0;
}


