/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	multiset<int> m;
	int sum=0;
	for(int i=0;i<n;i++){
		int tt;
		cin>>tt;
		if(tt==1){
			int a;cin>>a;
			m.insert(a);
		}else if(tt==2){
			int a;cin>>a;sum+=a;
		}else {
			cout<<(*m.begin())+sum<<endl;
			m.erase(m.find(*m.begin()));
		}
	}
}