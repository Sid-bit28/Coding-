/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define fr(i,n) for(int i=0;i<n;++i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;    typedef vector<int> vi;
typedef vector<pii> vii;      typedef vector<vi> graph; 
long long INF = 1e18;         long long MOD = 1e9+7;

void Solve() {
	int n;
	cin>>n;
	vi arr(n+1,0);
	rep(i,1,n){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	
	auto q = [&](int m) -> int {
		cout<<"? "<<m<<" ";
		rep(i,1,m){
			cout<<i;
			if(i!=m)cout<<" ";
		}
		cout<<endl;
		int sum;
		cin>>sum;
		return sum;
	};
	
	int low=1;
	int high=n;
	int ans=n;
	while(low<=high){
		int mid=(high+low)/2;
		if(q(mid)!=arr[mid]){
			ans=mid;
			high=mid-1;
		}else low=mid+1;
	}
	cout<<"! "<<ans<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		Solve();
	}
	return 0;
}