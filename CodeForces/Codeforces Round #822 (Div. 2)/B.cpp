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
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				if(j == 0 || j == i){
					cout << "1 ";
				}else cout << "0 ";
			}
			cout << endl;
		}
	}
}