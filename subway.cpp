#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 3010;
bool cyc[MAX_N], vis[MAX_N];
int dist[MAX_N];
vector<int> G[MAX_N];
int find_cycle(int x, int p)
{
  vis[x] = true;
  for (int i = 0; i < G[x].size(); i++) if (G[x][i] != p) {
      if (vis[G[x][i]]) {
	cyc[x] = true;
	for (int j = 0; j < G[x].size(); j++)
	  G[0].push_back(G[x][j]);
	return G[x][i];
      }
      int r;
      if ((r = find_cycle(G[x][i], x)) != -1) {
	cyc[x] = true;
	for (int j = 0; j < G[x].size(); j++)
	  G[0].push_back(G[x][j]);
	return (x==r)?-1:r;
      }
    }
  return -1;
}
int dfs(int x, int p, int d)
{
  dist[x] = d;
  for (int i = 0; i < G[x].size(); i++)
    if (G[x][i] != p && !cyc[G[x][i]])
      dfs(G[x][i], x, d+1);
}
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  find_cycle(1, -1);
  dfs(0,-1, 0);
  for (int i = 1; i <= n; i++)
    cout<<dist[i]<<" "; cout<<endl;
  return 0;
}
