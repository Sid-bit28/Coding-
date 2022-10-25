/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		vector<pair<int,int>> ans;
		int x=arr[0];
		if(x&1){
			vector<int> odd;
			for(int i = 0; i < n; i++){
				if(arr[i]&1)odd.push_back(i);
			}
			for(int i = (int)odd.size()-2; i >= 0; i--){
				ans.push_back({odd[i]+1,odd.back()+1});
			}
			for(int i = 0; i < n; i++){
				if(arr[i]%2==0){
					ans.push_back({1,i+1});
				}
			}
		}else {
			vector<int> even;
			for(int i = 0; i < n; i++){
				if(arr[i]%2==0)even.push_back(i);
			}
			for(int i = (int)even.size()-2; i >= 0; i--){
				ans.push_back({even[i]+1,even.back()+1});
			}
			for(int i = 0; i < n; i++){
				if(arr[i]&1){
					ans.push_back({1,i+1});
				}
			}
		}
		cout << (int)ans.size() << endl;
		for(auto x:ans){
			cout << x.first << " " << x.second << endl;
		}
	}
}