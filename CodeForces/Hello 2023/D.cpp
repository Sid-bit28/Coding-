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
    int n;
    cin>>n;
    vi arr(n),brr(n);
    fr(i,n){
    	cin>>arr[i];
    }
    fr(i,n){
    	cin>>brr[i];
    }
    arr.pb(INF);
    brr.pb(INF);
    int m;
    cin>>m;
    map<int,int> mp;
    fr(i,m){
    	int x;
    	cin>>x;
    	mp[x]++;
    }
    fr(i,n){
    	if(brr[i]>arr[i]){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    vi nx(n+1,-1);
    vi a;
    fr(i,n+1){
    	if(a.empty()){
    		a.pb(i);
    	}else {
    		if(brr[i]<=brr[a.back()]){
    			a.pb(i);
    		}else {
    			while(sz(a)>0&&brr[i]>brr[a.back()]){
    				if(arr[a.back()]!=brr[a.back()])nx[a.back()]=i;
    				a.pop_back();
    			}
    			a.pb(i);
    		}
    	}
    }
    map<int,int> x;
    map<int,int> f;
    fr(i,n){
    	if(nx[i]==-1)continue;
    	if(x.find(brr[i])!=x.end()&&i<=x[brr[i]])continue;
    	x[brr[i]]=nx[i];
    	f[brr[i]]++;
    }
    // pr(f);
    for(auto x:f){
    	if(mp[x.F]<x.S){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    cout<<"YES"<<endl;
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