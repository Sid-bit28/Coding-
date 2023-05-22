#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(r/i*i>=l){
			ans.push_back(r/i*i);
		}else {
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<endl;
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