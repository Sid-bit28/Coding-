/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

int solve(string s,string t){
	int n=s.size();
	int m=t.size();
	unordered_map<char,int> mp1,mp2;
	for(int i=0;i<m;i++){
		mp1[t[i]]++;
	}
	for(int i=0;i<n;i++){
		mp2[s[i]]++;
	}
	int ans=1e9;
	for(auto x:mp1){
		ans=min(ans,mp2[x.first]/x.second);
	}
	return ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s,t;
	cin>>s>>t;
	cout<<solve(s,t)<<endl;
}