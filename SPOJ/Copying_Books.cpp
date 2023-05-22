/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

int n,a,b;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=arr[0];
	for(int i=1;i<n;i++)
	{
		ans=__gcd(ans,arr[i]);
	}
	cout<<ans<<endl;
	
}