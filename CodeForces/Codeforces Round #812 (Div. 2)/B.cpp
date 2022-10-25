#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e6+10;
int k=1e9+7;
vector<int> f(mxN);
int find(int n, int r) {
    return (f[n] /(f[r] * f[n - r]))%k;
}
int check(string s,int a,int b){
     for(int i=0;i<s.length();i++){
      if((s[i]-'0')!=a && (s[i]-'0')!=b){
        return false;
      }
     }
     return true;
}
signed main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int a ,b ,n;
  cin>>a>>b>>n;
  f[0]=1;f[1]=1;
  for(int i=2;i<=n;i++){
  	f[i]=(f[i-1]*i)%k;
  }
  int cnt=n*a;
  int sum=0;
  for(int i=0;i<n;i++){
    string s=to_string(cnt);
    if(check(s,a,b)){
      if(a==b){
        cout<<"1"<<endl;
        return 0;
      }
      sum+=(find(n,i))%k;
    }
    cnt-=a;
    cnt+=b;
  }
  cout<<sum<<endl;
   return 0;
}