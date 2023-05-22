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

const int mxN=1e6+10;
vi p(mxN,1);
map<int,int> mp;
void pre(){
	p[0]=p[1]=0;
	rep(i,2,mxN-1){
		if(p[i]){
			for(int j=2*i;j<mxN;j+=i){
				p[j]=0;
			}
			mp[i]=1;
		}
	}
}

void solve(){
    int n,m;
    cin>>n>>m;
    auto it=mp.lower_bound(n+1);
    int v=(*it).F;
    int ans;
    if(v>=m){
    	ans=m-n-1;
    }else {
    	ans=v-n-1;
    }
    for(auto itt=it;itt!=mp.end();itt++){
    	int vv=(*itt).F;
    	if(vv>=m){
    		ans=max(ans,m-v-1);
    		break;
    	}else {
    		ans=max(ans,vv-v-1);
    		v=vv;
    	}
    }
    cout<<ans<<endl;
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