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
 
const int MAXN = 1<<18;
 
int n, k, a[MAXN], cnt;
set<int> comp;
map<int, int> cord;
long long tree[MAXN]; // BIT
 
long long ans, cur;
 
 
long long query(int idx){
    long long sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        comp.insert(a[i]);
    }
    
    for(auto it:comp) cord[it] = ++cnt;
    
    for(int i = 0; i < n; i++) a[i] = cord[a[i]];   // Co ordinate compression
 
    if(k == 0){ // All subarrys are valid
        cout << ((long long) n * 1LL * (n+1)) / 2LL << "\n";
        return 0;
    }
    
    update(a[0], 1);
    
    int s = 0, e = 0;
    while(s < n){
        while(e < n and cur < k){
            e++;
            if(e == n) break;
            
            update(a[e],1);
            // number of elements in [s,e] - number of elements <= a[e] = #elements > a[e]
            cur += (long long) (e-s+1) - (long long) query(a[e]); 
        }
        
        if(cur < k) break;
        
        ans += (long long) n-e; // all subarrays of the form [s,i] s.t. i >= e are valid.
                
        cur -= (long long) query(a[s]-1); // number of elements < a[s] = number of inversions due to a[s]
        update(a[s], -1);
        s++;
    }
    cout << ans << "\n";    
        
    return 0;
}