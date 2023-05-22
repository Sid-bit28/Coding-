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
vi pos(mxN);
void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    vi arr(n);
    fr(i,n) {
    	cin>>arr[i];
    	pos[arr[i]]=i;
    }
    vi a(m);
    fr(i,m) {
    	cin>>a[i];
    }
    int ans=INF;
    fr(i,m-1) {
    	if((pos[a[i+1]]-pos[a[i]]>d)||(pos[a[i+1]]<pos[a[i]])) {
    		cout<<0<<endl;
    		return;
    	}else {
    		ans=min(ans,pos[a[i+1]]-pos[a[i]]);
    		if(pos[a[i+1]]+d-(pos[a[i+1]]-pos[a[i]])+1<n) {
    			ans=min(ans,d-(pos[a[i+1]]-pos[a[i]])+1);
    		}else if(pos[a[i]]-d-(pos[a[i+1]]-pos[a[i]])+1>=0) {
    			ans=min(ans,d-(pos[a[i+1]]-pos[a[i]])+1);
    		}else if(n-1>d) {
    			ans=min(ans,d-(pos[a[i+1]]-pos[a[i]])+1);
    		}
    	}
    }
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