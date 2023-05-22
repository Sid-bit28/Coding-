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
    int n,c;
    cin>>n>>c;
    vi arr(n);
    vii left, v;
    fr(i,n) {
    	cin>>arr[i];
        left.pb(arr[i]+i+1,i);
        v.pb(min(arr[i]+i+1,arr[i]+n-i),i);
    }
    sort(all(left));
    sort(all(v));
    if(c<left[0].F) {
        cout<<0<<endl;
        return;
    }
    int ans=1;
    int t=left[0].S;
    int cc=c;
    c-=left[0].F;
    for(auto x:v) {
        if(x.S==t) continue;
        if(x.F>c) break;
        c-=x.F;
        ans++;
    }
    rep(i,1,n-1) {
        c=cc;
        if(left[i].F>c) {
            break;
        }
        t=left[i].S;
        c-=left[i].F;
        int val=1;
        for(auto x:v) {
            if(x.S==t) continue;
            if(x.F>c) break;
            c-=x.F;
            val++;
        }
        ans=max(ans,val);
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