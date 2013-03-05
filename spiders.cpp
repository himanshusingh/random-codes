#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> G[101];
bool vis[101];
int dist[101];
void dfs(int node, int d)
{
  vis[node] = true;
  dist[node] = d;
  for (int i = 0; i < G[node].size(); i++) if (!vis[G[node][i]])
    dfs(G[node][i], d + 1);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int trees;
  cin>>trees;
  int ans = 0;
  for (int t = 1; t <= trees; t++) {
    int nodes;
    cin>>nodes;
    int u, v;
    for (int n = 1; n <= nodes; n++) G[n].clear();
    for (int n = 1; n <= nodes - 1; n++) {
      cin>>u>>v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int n = 1; n <= nodes; n++) vis[n] = false;
    dfs(1, 0);
    int maxD = 0, maxN = 0;
    for (int n = 1; n <= nodes; n++) if (dist[n] > maxD) {
	maxD = dist[n];
	maxN = n;
      }
    for (int n = 1; n <= nodes; n++) vis[n] = false;
    dfs(maxN, 0);
    maxD = 0, maxN = 0;
    for (int n = 1; n <= nodes; n++) if (dist[n] > maxD) {
	maxD = dist[n];
	maxN = n;
      }
    ans += maxD;
  }
  cout<<ans<<endl;
  return 0;
}
