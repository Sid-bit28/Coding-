#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> oset;  // Functions as Multiset
// insert(x) to insert elements
// find_by_order(k)  returns iterator to kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define fr(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define endl '\n'

template<class T> bool umin(T& a, const T& b){return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b){return a<b?a=b, 1:0;}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x){
cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d=stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) 
{
  read(h);
  read(t...);
}
template<class A> void read(vt<A>& x) 
{
  for(auto &a : x)
    read(a);
}
template<class A, size_t S> void read(array<A, S>& x) 
{
  for(auto &a : x)
    read(a);
}

string to_string(char c) {
  return string(1, c);
}
string to_string(bool b) {
  return b?"true":"false";
}
string to_string(const char* s) {
  return string(s);
}
string to_string(string s) {
  return s;
}
string to_string(vt<bool> v) {
  string res;
  fr(i,sz(v))
  res+=char('0'+v[i]);
  return res;
}

template<size_t S> string to_string(bitset<S> b) 
{
  string res;
  fr(i,S)
  res+=char('0'+b[i]);
  return res;
}
template<class T> string to_string(T v) 
{
  bool f=1;
  string res;
  for(auto &x : v) {
    if(!f)
      res+=' ';
    f=0;
    res+=to_string(x);
  }
  return res;
}

template<class A> void write(A x) 
{
  cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) 
{ 
  write(h);
  write(t...);
}
void print() {
  write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) 
{ 
  write(h);
  if(sizeof...(t))
    write(' ');
  print(t...);
}

#ifndef SIDDARTH
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
#endif
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

#define int long long
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
	int n;
	read(n);
	vt<int> arr(n);
	read(arr);
	if(n&1) {
		int a=arr[0];
		rep(i, 1, n-1)
			a=a^arr[i];
		print(a);
	}else {
		int a=arr[0];
		rep(i, 1, n-1)
			a=a^arr[i];
		if(a==0)
			print(0);
		else 
			print(-1);
	}
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t=1;
  read(t);
  fr(i, t) {
    // write("Case #", i+1, ": ");
    solve();
  }
}