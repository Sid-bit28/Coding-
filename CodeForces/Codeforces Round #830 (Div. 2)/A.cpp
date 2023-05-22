/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

bool check(int a){
	for(int i=1;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int ans=arr[0];
		for(int i=1;i<n;i++){
			ans=__gcd(ans,arr[i]);
		}
		if(ans==1){
			cout<<0<<endl;
			continue;
		}
		int aans=1e7;
		vector<int> a=arr;
		for(int i=0;i<n;i++){
			a[i]=__gcd(a[i],i+1);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					if(__gcd(a[i],a[j])==1){
						aans=min(aans,n-i+n-j);
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			int ans=__gcd(arr[i],i+1);
			for(int j=0;j<n;j++){
				if(i!=j){
					ans=__gcd(ans,arr[j]);
				}
			}
			if(ans==1){
				aans=min(aans,n-i);
			}
		}
		cout<<aans<<endl;
	}
	return 0;
}