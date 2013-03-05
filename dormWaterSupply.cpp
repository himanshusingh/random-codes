#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 1024;
int in[MAX_N], out[MAX_N];
int n, p;
vector< pair<int, int> > G[MAX_N];
int start, end, diam;
void dfs(int x)
{
  if (!G[x].size()) { end = x; return; }
  dfs(G[x][0].first);
  diam = min(diam, G[x][0].second);    
}
int main()
{
  cin>>n>>p;
  for (int i = 0; i < p; i++) {
    int a, b, d;
    cin>>a>>b>>d;
    G[a].push_back(make_pair(b,d));
    in[b]++;
    out[a]++;
  }
  vector< pair < pair <int, int>, int > > res;
  for (int i = 1; i <= n; i++) if (!in[i] && out[i]) {
      diam = 1e7;
      start = i;
      dfs(i);
      res.push_back(make_pair(make_pair(start,end),diam));
    }
  cout<<res.size()<<endl;
  for (int i = 0; i < res.size(); i++)
    cout<<res[i].first.first<<" "<<res[i].first.second<<" "<<res[i].second<<endl;
  return 0;
}
