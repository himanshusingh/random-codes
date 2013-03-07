#include<iostream>
using namespace std;
bool G[19][19];
int dp[1<<19][19];
long long solve(int n)
{
  for (int i = 0; i < n; i++) dp[1<<i][i] = 1;

  for (int mask = 1; mask < 1<<n; mask++) {
    for (int i = 0; i < n; i++) if ((__builtin_ctz(mask) != i) && (mask & 1<<i)) {
	for (int j = 0; j < n; j++) if ((j != i) && (mask & 1<<j) && G[j][i]) {
	    dp[mask][i] += dp[mask^(1<<i)][j];
	  }
      }
  }
  long long ret = 0;
  for (int mask = 1; mask < 1<<n; mask++) 
    for (int i = 0; i < n; i++) if ((__builtin_popcount(mask) > 2) && G[i][__builtin_ctz(mask)]) {
	ret += dp[mask][i];
      }
  ret /= 2;
  return ret;      
}
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin>>u>>v;
    u--, v--;
    G[u][v] = G[v][u] = true; 
  }
  cout<<solve(n)<<endl;
  return 0;
}
