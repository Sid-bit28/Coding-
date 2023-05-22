/* SIDDARTH */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin>>tt;
	while(tt--){
		int m,f,c;
		cin>>m>>f>>c;
		int x = min({m,f,c});
		int ans=x;m-=x;f-=x;c-=x;
		if(m==0||f==0){
			cout<<ans<<endl;
		}else {
			while(m&&f){
				if(m>=2&&f>=1&&m>=f){
					m-=2;f-=1;ans++;
				}else if(f>=2&&m>=1&&m&&f){
					f-=2;m-=1;ans++;
				}else {
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
}