#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char,int> mp1,mp2;
	for(int i=0;i<n;i+=2){
		mp1[s[i]]++;
	}
	for(int i=1;i<n;i+=2){
		mp2[s[i]]++;
	}
	if(mp1==mp2){
		cout<<"YES"<<endl;
	}else cout<<"NO"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  	int t = 1;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
    return 0;
}