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
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void solve(){
	string s;
	cin>>s;
	int n=sz(s);
	rep(i,0,n-3) {
		if(s[i]=='M'&&s[i+1]=='O'&&s[i+2]=='O') {
			cout<<n-3<<endl;
			return;
		}
	}
	int ans=2;
	int ok=0;
	rep(i,1,n-2) {
		if(s[i]=='O'){
			ok=1;
			if(s[i-1]=='M'){
				ans=min(ans,1LL);
			}
			if(s[i+1]=='O'){
				ans=min(ans,1LL);
			}
		}
	}
	if(ok==0) {
		cout<<"-1"<<endl;
	}else {
		cout<<n-3+ans<<endl;
	}
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