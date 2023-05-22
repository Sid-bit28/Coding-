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

void solve(){
	int n,x;
	cin>>n>>x;
	if((x&n)!=x){
		cout<<"-1"<<endl;
		return;
	}
	vector<int> b(64,0);
	vector<int> bb(64,0);
	fr(i,64){
		if(x&(1LL<<i))b[i]++;
		if(n&(1LL<<i))bb[i]++;
	}
	vi ans(64,0);
	bool ok=0;
	for(int i=63;i>=0;i--){
		if(b[i]==0&&bb[i]==1){
			if(ok==0){
				ans[i+1]++;
				ok=1;
			}
		}else if(b[i]==1)ans[i]=1;
		
	}
	int v=0;
	fr(i,64){
		if(ans[i]==1)v+=(1LL<<i);
	}
	cout<<v<<endl;
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