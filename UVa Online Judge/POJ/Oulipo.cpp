#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

vector<int> KMP(string str){
	int n = str.length();
	vector<int> lps(n + 1);
	int i = 0, j = -1;
	lps[0] = -1;
	while(i < n){
		while(j != -1 && str[i] != str[j])j = lps[j];
		i++;j++;lps[i] = j;
	}
	return lps;
}

void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.length();
	int ans=0;
	s+='#';
	s+=t;
	vector<int> lps=KMP(s);
	for(int i=0;i<(int)lps.size();i++){
		ans+=(lps[i]==n);
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  	int t = 1;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
    return 0;
}