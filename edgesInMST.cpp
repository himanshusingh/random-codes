#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int MAX_N = int(1e5)+7;
int father[MAX_N];
int getf(int x)
{
  return (x==father[x])?x:father[x]=getf(father[x]);
}
struct edge
{
  int f, t;
  int id, w;
  bool operator<(const edge& x) const
  {
    return w < x.w;
  }
  edge(int _f,int _t,int _id,int _w):f(_f), t(_t), id(_id), w(_w) {}
};
vector<edge> edges;
int ans[MAX_N];
int tim[MAX_N], low[MAX_N], timer;
bool vis[MAX_N];
vector< pair<int, int> > G[MAX_N];
void bridge(int x, int parid)
{
  vis[x] = true;
  tim[x] = low[x] = ++timer;
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i].first, id = G[x][i].second;
    if (id == parid) continue;
    if (vis[y])
      low[x] = min(low[x], tim[y]);
    else {
      bridge(y, id);
      low[x] = min(low[x] , low[y]);
      if (tim[x] < low[y])
	ans[id] = 2;
    }
  }
}
void solve()
{
  for (int e = 0; e < edges.size();) {
    int w = edges[e].w, p = e;
    while (edges[e].w == w && e < edges.size()) ++e;
    map<int ,int> mp;
    int c = 0;
    for (int i = p; i < e; i++) {
      int a = edges[i].f, b = edges[i].t;
      int id = edges[i].id;
      a = getf(a), b = getf(b);
      if (a == b) continue;
      if (!mp[a]) mp[a] = ++c;
      if (!mp[b]) mp[b] = ++c;
    }
    for (int i = 1; i <= c; i++) G[i].clear(), vis[i] = false;
    for (int i = p; i < e; i++) {
      int a = getf(edges[i].f), b = getf(edges[i].t);
      int id = edges[i].id;
      if (a == b) continue;
      ans[id] = 1;
      a = mp[a], b = mp[b];
      G[a].push_back(make_pair(b, id));
      G[b].push_back(make_pair(a, id));
    }
    for (int i = 1; i <= c; i++) if (!vis[i]) timer = 0, bridge(i, -1);
    for (int i = p; i < e; i++) {
      int a = getf(edges[i].f), b = getf(edges[i].t);
      if (a != b) father[a] = b;
    }
  }
}
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 0; i <= n; i++) father[i] = i;
  for (int i = 0; i < m; i++) {
    int f, t, w;
    cin>>f>>t>>w;
    edges.push_back(edge(f, t, i, w));
  }
  sort(edges.begin(), edges.end());
  solve();
  for (int i = 0; i < m; i++)
    if (ans[i] == 0) cout<<"none"<<endl;
    else if (ans[i] == 1) cout<<"at least one"<<endl;
    else cout<<"any"<<endl;
  return 0;
}
