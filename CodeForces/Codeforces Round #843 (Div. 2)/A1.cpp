#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
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
    string s;
    cin>>s;
    int n=sz(s);
    int idx=-1;
    rep(i,1,n-2){
    	if(s[i]=='a'){
    		idx=i;
    	}
    }
    if(idx!=-1){
    	string a,b,c;
    	fr(i,n){
    		if(i<idx){
    			a.pb(s[i]);
    		}else if(i==idx){
    			b.pb(s[i]);
    		}else c.pb(s[i]);
    	}
    	cout<<a<<" "<<b<<" "<<c<<endl;
    	return;
    }
    string a,b,c;
    a.pb(s[0]);
    c.pb(s[n-1]);
    rep(i,1,n-2){
    	b.pb(s[i]);
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
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