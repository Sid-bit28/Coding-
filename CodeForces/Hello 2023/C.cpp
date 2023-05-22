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

// a+b+c+d+e
// a+b+c>=a+b+c+d => d <= 0
// a+b>=a+b+c+d => c+d <= 0
// a>=a+b+c+d => b+c+d <= 0

// a+b+c+d+e+f+g
// a+b+c+d+e>=a+b+c+d => e >= 0
// a+b+c+d+e+f>=a+b+c+d => e+f >= 0
// a+b+c+d+e+f+g>=a+b+c+d => e+f+g >= 0
void solve(){
	int n,m;
	cin>>n>>m;
	m--;
	vi arr(n);
	fr(i,n){
		cin>>arr[i];
	}
	
	priority_queue<long long,vector<long long>,greater<long long>>p;
	priority_queue<long long>q;
	int sum = 0;
	int ans=0;
	for(int i=m+1;i<n;i++){
		sum += arr[i];
		if(arr[i]<0) p.push(arr[i]);
		while(sum<0){
			ans++;
			int num = p.top();
			p.pop();
			sum -= 2*num;
		}
	}
	if(m!=0 && arr[m]>0) arr[m]*=-1,ans++;
	sum = arr[m];
	for(int i=m-1;i>=1;i--){
		sum += arr[i];
		if(arr[i]>0) q.push(arr[i]);
		while(sum>0){
			ans++;
			int num = q.top();
			q.pop();
			sum -= 2*num;
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