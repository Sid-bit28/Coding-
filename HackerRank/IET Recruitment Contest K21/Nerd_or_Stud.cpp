/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	int x=4*60-k;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x>=5*i){
			x-=5*i;
			ans++;
		}
	}
	cout<<ans<<endl;
}