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

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */
struct mi {
    int v; explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a;
}
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
istream& operator>>(istream&i,mi&a){i>>a.v;return i;}
ostream& operator<<(ostream&o,const mi&a){o<<a.v;return o;}

struct Factorials {
	vi invs, fac, ifac;
	void genFac(int N) {
		invs.resize(N), fac.resize(N), ifac.resize(N); 
		invs[1] = fac[0] = ifac[0] = 1; 
		rep(i,2,N-1) invs[i] = MOD-MOD/i*invs[MOD%i]%MOD;
		rep(i,1,N-1) {
			fac[i] = fac[i-1]*i%MOD;
			ifac[i] = ifac[i-1]*invs[i]%MOD;
		}
	}
	int C(int a, int b) {
		if (a < b || b < 0) return 0;
		return fac[a]*ifac[b]%MOD*ifac[a-b]%MOD; 
	}
};

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin>>n;
	vi arr(n);
	fr(i,n) {
		cin>>arr[i];
	}
	mi ans = 1;
	for(int i=0;i<n;i+=3) {
		int mx=max({arr[i]+arr[i+1],arr[i+1]+arr[i+2],arr[i]+arr[i+2]});
		int cnt=0;
		if(arr[i]+arr[i+1]==mx)cnt++;
		if(arr[i+1]+arr[i+2]==mx)cnt++;
		if(arr[i]+arr[i+2]==mx)cnt++;
		ans=ans*cnt;
	}
	
	Factorials f;
	f.genFac(1e5);
	ans=ans*f.C(n/3,n/6);
	cout<<ans<<endl;
}