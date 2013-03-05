#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX_N = 2e5+7;
struct edge
{
  int to;
  int dir;
  int c;
  int id;
  edge(int _to,int _dir,int _c,int  _id): to(_to), dir(_dir), c(_c),id(_id)
  {}
};
vector<edge> edges[MAX_N];
int hc[MAX_N], fc[MAX_N], ans[MAX_N];
bool vis[MAX_N];
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin>>a>>b>>c;
    edges[a].push_back(edge(b,0,c,i));
    edges[b].push_back(edge(a,1,c,i));
    fc[a] += c;
    fc[b] += c;
  }
  for (int i = 1; i <= n; i++) hc[i] = fc[i]/2;
  queue<int> Q;
  Q.push(1);
  vis[1] = true;
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (int i = 0; i < edges[node].size(); i++) {
      int to = edges[node][i].to, dir = edges[node][i].dir, id = edges[node][i].id, c = edges[node][i].c;
      if (vis[to]) continue;
      ans[id] = dir;
      hc[to] -= c;
      if (to != n && hc[to] == 0) Q.push(to), vis[to] = true;
    }
  }
  for (int i = 1; i <= m; i++) cout<<ans[i]<<endl;
  return 0;
}
