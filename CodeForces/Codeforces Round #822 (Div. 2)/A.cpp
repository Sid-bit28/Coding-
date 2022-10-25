/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

const int INF = 1e18;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(all(arr));
		int ans = INF;
		for(int i = 1; i < n - 1; i++){
			ans = min(ans, arr[i + 1] - arr[i] + arr[i] - arr[i - 1]);
		}
		cout << ans << endl;
	}
}