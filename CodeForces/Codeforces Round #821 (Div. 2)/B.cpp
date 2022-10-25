/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int n,x,y;
		cin>>n>>x>>y;
		if(x!=0&&y!=0){
			cout<<"-1"<<endl;
			continue;
		}
		x=max(x,y);
		if(x==0){
			cout<<"-1"<<endl;
			continue;
		}
		if((n-1)%x!=0){
			cout<<"-1"<<endl;
			continue;
		}
		int cur=1;
		int cnt=0;
		for(int i=2;i<=n;i++){
			if(cnt==x){
				cnt=0;
				cur=i;
			}
			cout<<cur<<" ";
			cnt++;
		}
		cout<<endl;
	}
}