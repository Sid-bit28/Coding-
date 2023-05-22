#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

int n;
string s,t;

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

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	while(cin>>n){
		cin>>s>>t;
		s+='#';
		s+=t;
		vector<int> lps=KMP(s);
		for(int i=0;i<(int)lps.size();i++){
			if(lps[i]==n){
				cout<<i-n<<endl;
			}
		}
		cout<<endl;
	}
    return 0;
}

// 2
// na
// banananobano
// 6
// foobar
// foo
// 9
// foobarfoo
// barfoobarfoobarfoobarfoobarfoo