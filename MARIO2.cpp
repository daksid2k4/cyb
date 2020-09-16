#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int maxn=500000;
int m,n,i,j,d[maxn],a,k;
typedef pair<int,int>ii;
vector<ii>g[maxn];
priority_queue<ii,vector<ii>,greater<ii> > q;

int main()
{
    cin>>n>>m;
    for (j=1; j<=n;++j)
    {
      k=m*(j-1);
      for (i=1; i<=m-1; ++i)
      {
         cin>>a;
         g[i+k].push_back(ii(a,i+k+1));
         g[i+k+1].push_back(ii(a,i+k));
      }
    }
    for (j=1; j<=n-1; ++j)
    {
      k=m*(j-1);
      for (i=1; i<=m; ++i)
      {
        cin>>a;
        g[i+k+m].push_back(ii(a,i+k));
        g[i+k].push_back(ii(a,i+k+m));
      }
    }


    for (i=1; i<=n*m; ++i) d[i]=INT_MAX;

    d[1]=0;
    q.push(ii(d[1],1));
    while (!q.empty())
    {
        int du=q.top().st; int u=q.top().nd; q.pop();
        if (du!=d[u]) continue;
        for (i=0; i<g[u].size(); ++i)
        {
            int l=g[u][i].st; int v=g[u][i].nd;
            if (d[v]>d[u]+l)
              {
                  d[v]=d[u]+l;
                  q.push(ii(d[v],v));
              }
        }

    }
    cout<<d[m*n];

   return 0;
}
