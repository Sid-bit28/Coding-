#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> oset;  // Functions as Multiset
// insert(x) to insert elements
// find_by_order(k)  returns iterator to kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k

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
#include "bits/debug.h"
#else
#define pr(...) {}
#endif
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void solve(){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    fr(i,n) {
    	cin >> arr[i];
    }
    
    auto get = [&](int i, int cnt) -> int {
    	int ans = arr[i];
    	fr(cnt1,cnt) {
    		int x = ans;
    		int sum = 0;
    		int iter = 0;
    		while(x) {
    			sum += x % 10;
    			x /= 10;
    			iter++;
    		}
    		ans = sum;
    		if(iter == 1) break;
    	}
    	return ans;
    };
    
    oset left, right;
    map<int,int> mp;
    fr(q1,q) {
    	int t;
    	cin >> t;
    	if(t == 1) {
    		int l, r;
    		cin >> l >> r;
    		--l; --r;
    		mp[l]++;
    		left.insert(l);
    		right.insert(r);
    	}else {
    		int x;
    		cin >> x;
    		--x;
    		int cnt = left.order_of_key(x) - right.order_of_key(x);
    		cnt += mp[x];
    		cout << get(x,cnt) << endl;
    	}
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