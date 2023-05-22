#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'
const int INF=1e18;


const int mxN=1e5+10;
int n,q;
vector<int> arr(mxN);

bool check(int mid){
	int tot=q;
	for(int i=0;i<n;i++){
		if(i>=mid){
			if(arr[i]>tot){
				tot--;
			}
		}
	}
	return tot>=0;
}

void solve(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int low=0;
	int high=n-1;
	int ans=n-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(check(mid)){
			ans=mid;
			high=mid-1;
		}else {
			low=mid+1;
		}
	}
	string aans(n,'0');
	for(int i=0;i<n;i++){
		if(i>=ans){
			if(arr[i]>q){
				aans[i]='1';
				q--;
			}else {
				aans[i]='1';
			}
		}else {
			if(arr[i]<=q){
				aans[i]='1';
			}
		}
	}
	cout<<aans<<endl;
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