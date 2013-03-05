#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 111;
vector<int> G[MAX_N];
vector<int> T[MAX_N];
int color[MAX_N];
bool vis[MAX_N], ok;
void dfs(int x, int p)
{
  vis[x] = true;

  for (int y, t, i = 0; i < G[x].size(); i++) {
    y = G[x][i], t = T[x][i];
    if (y == p) continue;
    if (vis[y]) {
      if (t && (color[x] != color[y])) ok = false;
      if (!t && (color[x] == color[y])) ok = false;
    } else {
      if (t) color[y] = color[x];
      else color[y] = !color[x];
      dfs(y,x);
    }
  }
}

int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin>>a>>b>>t;
    G[a].push_back(b);
    G[b].push_back(a);
    T[a].push_back(t);
    T[b].push_back(t);
  }
  bool valid = true;
  for (int i = 1; i <= n; i++) color[i] = -1;
  for (int i = 1; i <= n; i++) if (color[i] == -1) {
      for (int j = 1; j <= n; j++) vis[j] = false;
      color[i] = 0;
      ok = true;
      dfs(i, -1);
      if (ok) continue;
      for (int j = 1; j <= n; j++) vis[j] = false;
      color[i] = 1;
      ok = true;
      dfs(i,-1);
      if (!ok) {valid = false; break;}
    }
  if (!valid)
    cout<<"Impossible"<<endl;
  else {
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (color[i]) cnt++;
    cout<<cnt<<endl;
    for (int i = 1; i <= n; i++) if (color[i]) cout<<i<<" ";cout<<endl;
  }
  return 0;
}
