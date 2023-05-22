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
    int n,s;
    cin>>n>>s;
    vi arr(n);
    fr(i,n) {
    	cin>>arr[i];
    }
    
    vii v;
    rep(i,1,n-2) {
    	if(arr[i]>=s) {
    		v.pb(s,abs(s-arr[i]));
    	}else {
    		v.pb(0,arr[i]);
    	}
    }
    
    vector<vector<int>> dp(n-2, vector<int> (2,-1));
    auto rec = [&](auto rec, int pos, int last) -> int {
    	if(pos==sz(v)) {
    		if(last==0) {
    			return v[pos-1].S*arr[n-1];
    		}else {
    			return v[pos-1].F*arr[n-1];
    		}
    	}
    	if(dp[pos][last]!=-1) return  dp[pos][last];
    	int ans=INF;
    	if(last==0) {
    		ans=min({ans, v[pos].F*v[pos-1].S+rec(rec,pos+1,0), v[pos].S*v[pos-1].S+rec(rec,pos+1,1)});
    	}else {
    		ans=min({ans, v[pos].F*v[pos-1].F+rec(rec,pos+1,0), v[pos].S*v[pos-1].F+rec(rec,pos+1,1)});
    	}
    	return dp[pos][last]=ans;
    };
    
    int ans=min(arr[0]*v[0].F+rec(rec,1,0),arr[0]*v[0].S+rec(rec,1,1));
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