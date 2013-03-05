#include<iostream>
using namespace std;
const int oo = 1000000000;
int G[66][66][66];
int n, m, rounds;
int dp[66][66][66];
int main()
{
  cin>>n>>m>>rounds;
  for (int c = 1; c <= m; c++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) cin>>G[c][i][j];
  
  for (int c = 1; c <= m; c++)
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	  G[c][i][j] = min(G[c][i][j], G[c][i][k] + G[c][k][j]);
  
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
	dp[i][j][0] = oo;
	for (int c = 1; c <= m; c++) dp[i][j][0] = min(dp[i][j][0], G[c][i][j]);
      }

    for (int c = 1; c <= 60; c++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
	  dp[i][j][c] = dp[i][j][c-1];
	  for (int k = 1; k <= n; k++)
	    dp[i][j][c] = min(dp[i][j][c], dp[i][k][c-1] + dp[k][j][0]);
	}

    for (int r = 1; r <= rounds; r++) {
      int s, t, k;
      cin>>s>>t>>k;
      cout<<dp[s][t][min(k, n)]<<endl;
    }
  return 0;
}
