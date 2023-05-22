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
	cin >> tt;
	while(tt--){
		int n,x,y;
		cin>>n>>x>>y;
		string a,b;
		cin>>a>>b;
		vector<int> arr(n,0);
		for(int i = 0; i < n; i++){
			arr[i] = a[i]-'0';
		}
		vector<int> pos;
		for(int i = 0; i < n; i++){
			arr[i] = (arr[i] + b[i] - '0') % 2;
			if(arr[i] & 1){
				pos.push_back(i);
			}
		}
		int xx = (int)pos.size();
		if(xx == 0){
			cout << 0 << endl;
			continue;
		}
		if(xx & 1){
			cout << "-1" << endl;
			continue;
		}
		int ans = xx / 2 * y;
		if(xx > 2){
			cout << ans << endl;
			continue;
		}
		if(pos[0] + 1 != pos[1]){
			cout << ans << endl;
			continue;
		}
		ans = x;
		if(pos[0] - 1 > 0 || pos[1] + 1 < n - 1){
			ans = min(ans, 2 * y);
		}
		if(pos[0] > 0 && pos[1] < n - 1){
			ans = min(ans, 3 * y);
		}
		cout << ans << endl;
	}
}