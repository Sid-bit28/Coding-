/*
ID: Moralizer_28
LANG: C++17
TASK: speeding
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

#ifndef SIDDARTH
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define pr(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#endif

signed main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  freopen("speeding.in","r",stdin);
  freopen("speeding.out","w",stdout);
  int n, m;
  cin >> n >> m;
  int l=1;
  vector<int> p(110, 0), pp(110, 0);
  for(int i=0;i<n;i++) {
    int a, b;
    cin >> a >> b;
    p[l]+=b;
    p[l+a]-=b;
    l+=a;
  }
  for(int i=1;i<105;i++) {
    p[i]+=p[i-1];
  }
  l=1;
  for(int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    pp[l]+=b;
    pp[l+a]-=b;
    l+=a;
  }
  for(int i=1;i<105;i++) {
    pp[i]+=pp[i-1];
  }
  int ans=0;
  for(int i=1;i<=100;i++) {
    ans=max(ans, pp[i]-p[i]);
  }
  cout << ans << endl;
}