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

const int mxN = 1e6+10;
vi ans1(mxN);
vi ans2(mxN);
void pre() {
	int curr = 1;
	int sum = curr * (curr + 1)/2;
	int ok = 1;
	rep(i,1,mxN-1) {
		ans1[i] = ans1[i - 1];
		ans2[i] = ans2[i - 1];
		if(ok) {
			ans1[i]++;
		}else ans2[i]++;
		if(i == sum) {
			ok = 1 - ok;
			curr += 2;
			sum = curr * (curr + 1)/2;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	cout << ans1[n] << " " << ans2[n] << endl;
}

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