/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

#ifndef ONLINE_JUDGE
#include "Debug.h"
#else
#define pr(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#endif

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;cin >> n;
		string s;cin >> s;
		vector<int> a(n + 1,1);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				a[i + 1] = 0;cnt++;
			}
		}
		vector<int> arr = a;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j += i){
				if(a[j] == 1)break;
				if(arr[j] == 0)ans += i;
				arr[j] = 1;
			}
		}
		cout << ans << endl;
	}
}