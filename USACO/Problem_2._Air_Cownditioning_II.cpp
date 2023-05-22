/* SIDDARTH */
#include <bits/stdc++.h>
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

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N,M;
	cin>>N>>M;
	vi s(N),t(N),c(N);
	fr(i,N) {
		cin>>s[i]>>t[i]>>c[i];
	}
	vi a(M),b(M),p(M),m(M);
	fr(i,M) {
		cin>>a[i]>>b[i]>>p[i]>>m[i];
	}
	
	auto rec = [&](auto rec, int pos, vi cool) -> int {
		if(pos==M) {
			rep(i,1,100) {
				cool[i]+=cool[i-1];
			}
			int ok=0;
			fr(i,N) {
				rep(j,s[i],t[i]) {
					if(cool[j]<c[i]) {
						ok=1;
					}
				}
			}
			if(ok==0) {
				return 0;
			}else return INF;
		}
		int ans=INF;
		ans=min(ans, rec(rec, pos+1, cool));
		cool[a[pos]]+=p[pos];
		cool[b[pos]+1]-=p[pos];
		ans=min(ans, m[pos]+rec(rec, pos+1, cool));
		return ans;
	};
	
	vi cool(102,0);
	int ans=rec(rec, 0, cool);
	cout<<ans<<endl;
}