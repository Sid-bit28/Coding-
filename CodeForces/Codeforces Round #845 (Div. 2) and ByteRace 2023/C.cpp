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

const int mxN=1e5+10;
map<int,vi> mp;
void pre() {
	for(int i=1;i<mxN;i++){
		for(int j=i;j<mxN;j+=i){
			mp[j].push_back(i);
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	vi arr(n);
	fr(i,n){
		cin>>arr[i];
	}
	sort(all(arr));
	// pr(mp[16]);
	
	int j=0;
	set<int> temp;
	map<int,int> f;
	
	int ans=INF;
	fr(i,n){
		for(auto x:mp[arr[i]]){
			if(x>m)break;
			f[x]++;
			temp.insert(x);
		}
		if(sz(temp)==m){
			while(sz(temp)==m){
				for(auto x:mp[arr[j]]){
					if(x>m)break;
					f[x]--;
					if(f[x]==0)temp.erase(x);
				}
				j++;
			}
			ans=min(ans,arr[i]-arr[j-1]);
		}
	}
	if(ans==INF)ans=-1;
	cout<<ans<<endl;
}
// 3 4 5 6 7
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    // freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	pre();
	int TC = 1;
	cin >> TC;
	for(int i = 1; i <= TC; ++i){
        //cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}