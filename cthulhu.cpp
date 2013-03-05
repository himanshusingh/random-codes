#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 110;
bool vis[MAX_N];
vector<int> G[MAX_N];
int dfs(int x)
{
  vis[x] = true;
  for (int i = 0; i < G[x].size(); i++) if (!vis[G[x][i]]) dfs(G[x][i]);
}
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool ok = (m==n);
  dfs(1);
  for (int i = 1; i <= n; i++) if (!vis[i]) ok = false;
  if (!ok)
    cout<<"NO"<<endl;
  else
    cout<<"FHTAGN!"<<endl;
  return 0;
}
