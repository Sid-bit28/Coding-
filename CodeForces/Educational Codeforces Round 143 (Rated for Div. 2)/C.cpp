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
#include "bits/debug.h"
#else
#define pr(...) {}
#endif
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void solve(){
    int n;
    cin>>n;
    vi arr(n+1,0), brr(n+1,0);
    rep(i,1,n) {
    	cin >> arr[i];
    }
    rep(i,1,n) {
    	cin >> brr[i];
    }
    vi p(n+1,0);
    rep(i,1,n) {
    	p[i]+=p[i-1];
    	p[i]+=brr[i];
    }
    vi ans(n+2,0);
    vi times(n+2,0);
    int tot = 0;
    rep(i,1,n) {
    	tot += brr[i - 1];
    	int naya = arr[i] + tot;
    	auto it=lower_bound(p.begin(),p.end(),naya);
    	if(it!=p.end()) {
    		int idx=distance(p.begin(),it);
    		times[i]++;
    		if(p[idx]==naya) {
    			times[idx+1]--;
    		}else {
    			times[idx]--;
    			ans[idx]+=naya-p[idx-1];
    		}
    	}else {
    		times[i]++;
    	}
    }
    rep(i,1,n) {
    	times[i]+=times[i-1];
    	ans[i]+=brr[i]*times[i];
    }
    rep(i,1,n) {
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
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