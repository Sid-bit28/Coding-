/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)
const int INF=1e18;

const int mxN=1010;
string s,temp;
int dp[mxN][mxN];
int rec(int i,int j){
	if(j-i<1){
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	int ans=INF;
	if(s[i]==s[j]){
		ans=rec(i+1,j-1);
	}else {
		ans=min({ans,1+rec(i+1,j),1+rec(i,j-1),1+rec(i+1,j-1)});
	}
	return dp[i][j]=ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	for(int i=1;i<=tt;i++){
		cin>>s;
		memset(dp,-1,sizeof(dp));
		printf("Case %lld: %lld\n", i, rec(0,s.size()-1));
	}
}