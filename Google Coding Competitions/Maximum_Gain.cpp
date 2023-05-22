#include"bits/stdc++.h"
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
typedef long long lli;         typedef long double ld;
typedef pair<lli,lli> pii;     typedef vector<lli> vi;
typedef vector<pii> vii;       typedef vector<vi> graph;
const long long MOD=1000000007;const long long INF=1e18;

const int mxN=6060;
lli n,m,k;
vi arr(mxN),brr(mxN);
void pre(){
	
}
void solve(){
	cin>>n;
	fr(i,n){cin>>arr[i];}
	cin>>m;
	fr(i,m){cin>>brr[i];}
	cin>>k;
	
	
	
	vi pref1(n+1,0),pref2(m+1,0),suf1(n+1,0),suf2(m+1,0);
	fr(i,n){
		pref1[i+1]=pref1[i]+arr[i];
	}
	fr(i,m){
		pref2[i+1]=pref2[i]+brr[i];
	}
	lli sum=0;
	for(int i=n-1;i>=0;i--){
		sum+=arr[i];
		suf1[i+1]=sum;
	}
	sum=0;
	for(int i=m-1;i>=0;i--){
		sum+=brr[i];
		suf2[i+1]=sum;
	}
	
	pref1.push_back(0);
	pref2.push_back(0);
	suf1.push_back(0);
	suf2.push_back(0);
	lli ans=0;
	for(int i=0;i<=k;i++){
		if(i<=n&&(k-i)<=m){
			lli sum1=0;
			for(int j=0;j<=i;j++){
				sum1=max(sum1,pref1[j]+suf1[n-(i-j)+1]);
			}
			lli sum2=0;
			for(int j=0;j<=(k-i);j++){
				sum2=max(sum2,pref2[j]+suf2[m-((k-i)-j)+1]);
			}
			ans=max(ans,sum1+sum2);
		}
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    pre();lli _t=1;cin>>_t;
    for(lli i=1;i<=_t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
