#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;

set<char> vowel;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int pehla=1;
	int last=-1;
	for(int i=0;i<n;i++){
		if(pehla==0 && vowel.find(s[i]) != vowel.end()){
			if(i-last-1>=4){
				cout<<"NO"<<endl;
				return;
			}
			last=i;
		}else if(vowel.find(s[i])!=vowel.end()){
			if(i>=4){
				cout<<"NO"<<endl;
				return;
			}
			pehla=0;
			last=i;
		}
	}
	if(pehla==1){
		if(n>=4){
			cout<<"NO"<<endl;
			return;
		}
	}
	if(n-last-1>=4){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	vowel.insert('a');
	vowel.insert('e');
	vowel.insert('i');
	vowel.insert('o');
	vowel.insert('u');
  	int t = 1;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
    return 0;
}