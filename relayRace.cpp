#include<iostream>
using namespace std;
const int oo = 1e9;
int G[301][301];
int dp[301*2][301][301];
int n;
int memo(int p, int x1, int x2)
{
  int y1 = p-x1, y2 = p-x2;
  if (y1 > n || x1 > n || y2 > n || x2 > n) return -oo;
  if (p == n+n) return G[n][n];
  if (dp[p][x1][x2] != -oo) return dp[p][x1][x2];
  int ans = G[x1][y1] + ((x1==x2)?0:G[x2][y2]);
  int ret = -oo;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ret = max(ret, memo(p+1, x1+i, x2+j));
  return dp[p][x1][x2] = ans + ret;
}
int main()
{
  cin>>n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin>>G[i][j];
  for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) dp[i][j][k] = -oo;
  cout<<memo(2,1,1)<<endl;
}
