/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)


void Solve(){
	int n,k;
	cin >> n >> k;--k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if(arr[k] < 0){
		cout << "NO" << endl;
		return;
	}
	if(k == 0 || k == n - 1){
		cout << "YES" << endl;
		return;
	}
	bool ok1 = true, ok2 = true;
	int sum = arr[k];
	int left = k - 1; int right = k + 1;
	while(left >= 0 && right < n){
		if(arr[left] <= arr[right]){
			sum += arr[right];right++;
		}else {
			sum += arr[left];left--;
		}
		if(sum < 0){
			ok1 = false;
			break;
		}
	}
	sum = arr[k];
	left = k - 1; right = k + 1;
	while(left >= 0 && right < n){
		if(arr[left] < arr[right]){
			sum += arr[right];right++;
		}else {
			sum += arr[left];left--;
		}
		if(sum < 0){
			ok2 = false;
			break;
		}
	}
	if(!ok1 && !ok2){
		cout << "NO" << endl;
	}else cout << "YES" << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	while(tt--){
		Solve();
	}
}