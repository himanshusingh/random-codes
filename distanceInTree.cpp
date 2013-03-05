#include <iostream>
#include <vector>
using namespace std;
int dp[50001][501];
long long ans;
int k;
vector<int> G[50001];
bool vis[50001];
void dfs(int node)
{
  vis[node] = true;
  dp[node][0] = 1;
  for (int i = 0; i < G[node].size(); i++) if (!vis[G[node][i]]) {
      int v = G[node][i];
      dfs(v);
      for (int d = 0; d < k; d++)
	ans += dp[node][d]*dp[v][k - d - 1];
      for (int d = 0; d < k; d++)
	dp[node][d + 1] += dp[v][d];
    }
}
int main()
{
  int n;
  cin>>n>>k;
  ans = 0;
  int root = 1;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(root);
  cout<<ans<<endl;
  return 0;
}
