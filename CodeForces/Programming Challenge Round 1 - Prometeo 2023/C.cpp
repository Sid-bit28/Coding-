#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb emplace_back
#define MP make_pair
#define int long long
#define all(o) (o).begin(), (o).end()
#define fr(i,n) for(int i=0;i<n;++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x).size()
#define endl '\n'
typedef pair<int,int> pii;    typedef vector<int> vi;
typedef vector<pii> vii;      typedef vector<vi> graph; 
long long INF = 1e18;         long long MOD = 1e9+7;
#ifndef ONLINE_JUDGE
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#include "debug.cpp"
#else
#define pr(...) {}
#endif
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

int dp[101][101][101];
void solve(){
	int n,k;
	cin>>n>>k;
	vi r(n+1,0),g(n+1,0);
	vi arr(n+1);
	rep(i,1,n){
		cin>>arr[i];
		if(arr[i]==1)r[i]++;
		else g[i]++;
		r[i]+=r[i-1];
		g[i]+=g[i-1];
	}
	
	auto rec = [&](auto rec,int pos,int p,int last) -> int {
		// pr(pos,p,last);
		if(pos==n+1){
			if(p==k){
				return 0;
			}else return INF;
		}
		if(p==k){
			return INF;
		}
		if(dp[pos][p][last]!=-1)return dp[pos][p][last];
		int ans=rec(rec,pos+1,p,last);
		ans=min(ans,(g[pos]-g[last])*(r[pos]-r[last])+rec(rec,pos+1,p+1,pos));
		return dp[pos][p][last]=ans;
	};
	
	memset(dp,-1,sizeof(dp));
	int ans=rec(rec,1,0,0);
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    // freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	int TC = 1;
	cin >> TC;
	for(int i = 1; i <= TC; ++i){
        //cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}