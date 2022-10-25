/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	
	for(int i = 2; i <= 26; i++){
		int a,b;
		cout << "? 1 " << i << endl;
		cin >> a;
		cout << "? " << i << " 1" << endl;
		cin >> b;
		if(a == -1){
			cout << "! " << i-1 << endl;
			return 0;
		}
		if(a!=b){
			cout << "! " << a+b << endl;
			return 0;
		}
	}
	return 0;
}