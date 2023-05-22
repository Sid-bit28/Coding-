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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto x : s) {
    	mp[x]++;
    }
    
    int ans = 0;
    fr(i, 26) {
    	ans += min(mp['a' + i], mp['A' + i]);
    	int mn = min(mp['a' + i], mp['A' + i]);
    	mp['a' + i] -= mn;
    	mp['A' + i] -= mn;
    	if(mp['a' + i] / 2 <= k) {
    		ans += mp['a' + i] / 2;
    		k -= mp['a' + i] / 2;
    	}else {
    		ans += k;
    		k = 0;
    	}
    	if(mp['A' + i] / 2 <= k) {	
    		ans += mp['A' + i] / 2;
    		k -= mp['A' + i] / 2;
    	}else {
    		ans += k;
    		k = 0;
    	}
    }
    cout << ans << endl;
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