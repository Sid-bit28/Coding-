#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int inf=1e18;

void solve(){
	int n,c,q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	set<pair<int,int>> p;
	p.insert({inf,inf});
	int curr_index=n;
	for(int i = 0; i < c; i++){
		int a,b;
		cin >> a >> b;
		--a,--b;
		p.insert({curr_index,a});
		curr_index+=(b-a+1);
	}
	while(q--){
		int k;
		cin>>k;
		--k;
		while(k>=n){
			auto it=p.upper_bound({k,inf});
			it--;
			k=k-(*it).first+(*it).second;
		}
		cout<<s[k]<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  	int t;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
    return 0;
}