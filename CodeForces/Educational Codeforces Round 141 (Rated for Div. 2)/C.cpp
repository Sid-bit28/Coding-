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
    int n,m;
    cin>>n>>m;
    vi arr(n);
    fr(i,n){
    	cin>>arr[i];
    }
    
    auto check = [&](int rank) -> bool {
    	int t=0;
    	
    };
    
    int low=1;
    int high=n;
    int ans=n;
    while(low<=high){
    	int mid=(high+low)/2;
    	if(check(mid)){
    		ans=mid;
    		high=mid-1;
    	}else low=mid+1;
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