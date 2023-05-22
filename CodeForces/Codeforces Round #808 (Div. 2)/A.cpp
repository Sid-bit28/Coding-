#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<n;i++){
		if(arr[i]%arr[0]!=0){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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