/*
ID: Moralizer_28
LANG: C++17
TASK: shuffle
*/
#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  freopen("shuffle.in","r",stdin);
  freopen("shuffle.out","w",stdout);
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  vector<string> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  auto calc=[&](vector<string> &a)->void{
    vector<string> ans(n);
    for(int i = 0; i < n; i++) {
      ans[i]=a[arr[i]-1];
    }
    a=ans;
  };
  
  for(int i = 0; i < 3; i++) {
    calc(a);
  }
  for(int i = 0; i < n; i++)
    cout << a[i] << endl;
}