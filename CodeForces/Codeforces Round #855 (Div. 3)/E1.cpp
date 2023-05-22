#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#define SIZE 200005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

vector <ll> vec[SIZE];
ll mx[SIZE];
ll ans[SIZE];

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
  {
    int c,v;
    scanf("%d %d",&c,&v);c--;
    vec[c].push_back(v);
  }
  vector <P> vx;
  for(int i=0;i<m;i++)
  {
    sort(vec[i].begin(),vec[i].end(),greater <ll>());
    vx.push_back(P(vec[i][0]+vec[i][1],i));
  }
  sort(vx.begin(),vx.end(),greater <P>());
  for(int i=m-1;i>=0;i--)
  {
    int t=vx[i].second;
    mx[i]=-INF;
    if(vec[t].size()>=3) mx[i]=vec[t][0]+vec[t][1]+vec[t][2];
    if(i+1<m) mx[i]=max(mx[i],mx[i+1]);
  }
  priority_queue <ll> que;
  int to=0,cnt=0;
  ll sum=0,last=INF;
  for(int i=1;i<=n;i++) ans[i]=-INF;
  while(1)
  {
    if(last<INF)
    {
      sum-=last;
      que.push(last);
      last=que.top();
      sum+=last;
      que.pop();
      ans[cnt]=max(ans[cnt],sum);
    }
    if(que.size()>0) ans[cnt+1]=max(ans[cnt+1],sum+que.top());
    if(to<m) ans[cnt+3]=max(ans[cnt+3],sum+mx[to]);
    if(que.size()>0&&to<m)
    {
      ans[cnt+3]=max(ans[cnt+3],sum+que.top()+vx[to].first);
      ans[cnt+4]=max(ans[cnt+4],sum+mx[to]+que.top());
    }
    if(last<INF)
    {
      ans[cnt-1]=max(ans[cnt-1],sum-last);
      if(to<m) ans[cnt+2]=max(ans[cnt+2],sum-last+mx[to]);
    }
    if(que.size()<2)
    {
      if(to==m) break;
      int t=vx[to++].second;
      sum+=vec[t][0]+vec[t][1];
      for(int i=2;i<vec[t].size();i++) que.push(vec[t][i]);
    }
    else
    {
      ll a=que.top();que.pop();
      ll b=que.top();que.pop();
      if(to==m||a+b>vx[to].first)
      {
        sum+=a+b;
        last=min(last,b);
      }
      else
      {
        que.push(a);que.push(b);
        int t=vx[to++].second;
        sum+=vec[t][0]+vec[t][1];
        for(int i=2;i<vec[t].size();i++) que.push(vec[t][i]);
      }
    }
    cnt+=2;
    ans[cnt]=max(ans[cnt],sum);
  }
  for(int i=1;i<=n;i++)
  {
    if(ans[i]<0) puts("-1");
    else printf("%lld\n",ans[i]);
  }
  return 0;
}
