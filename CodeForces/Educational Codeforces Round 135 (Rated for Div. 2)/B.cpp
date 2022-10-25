/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

//  1 5 4 3 2 6 7
//0 1 6 0 3 0 6 13
//  1 2 3 4 5 6 7 8
//0 1 3 0 1 9 0 7 15
//  7 6 5 4 3 2 1 8 9 
//0 7 0 5 0 3 0 1
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		if(n%2){
			for(int i = 5; i < n; i += 2){
				cout<<i<<" "<<i-1<<" ";
			}
			cout << 2 << " " << 3 << " " << 1 << " " << n - 1 << " " << n << endl;
		}else {
			for(int i = 2; i < n; i += 2){
				cout<<i<<" "<<i-1<<" ";
			}
			cout<<n-1<<" "<<n<<endl;
		}
	}
}