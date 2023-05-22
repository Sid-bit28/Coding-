/*
ID: Moralizer_28
LANG: C++17
TASK: blist
*/
#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long
#define vt vector;
typedef pair<int, int> pii;

const int mxN = 110;
int a[mxN], b[mxN], c[mxN];
int start[1001], finish[1001];
int n;

signed main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  freopen("blist.in","r",stdin);
  freopen("blist.out","w",stdout);
  cin >> n;
  rep(i, 1, n)
    cin >> a[i] >> b[i] >> c[i];
  
  rep(i, 1, n) {
    start[a[i]]=i;
    finish[b[i]]=i;
  }
  
  int b=0, ans=0;
  rep(i, 1, 1000) {
    if(start[i]) 
      b+=c[start[i]];
    ans=max(ans, b);
    if(finish[i])
      b-=c[finish[i]];
  }
  cout << ans << endl;
}