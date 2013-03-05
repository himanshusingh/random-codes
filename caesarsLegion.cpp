#include<iostream>
#include<cstring>
using namespace std;

int memo[101][101][11][11];
int dp[102][102][11][11];
const int mod = 1e8;
int n1, n2, k1, k2;
int solve(int n, int m, int p, int q)
{
  int& ret = memo[n][m][p][q];
  if (ret != -1) return ret;
  if (n == n1 && m == n2) return memo[n][m][p][q] = 1;
  ret = 0;
  if (n < n1 && p < k1) ret = (ret + solve(n+1, m, p + 1, 0))%mod;
  if (m < n2 && q < k2) ret = (ret + solve(n, m+1, 0, q+1))%mod;
  return ret;
}
int main()
{

  for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++) for (int k = 0; k <= 10; k++) for(int l = 0; l <= 10; l++) memo[i][j][k][l] = -1;
  
  cin>>n1>>n2>>k1>>k2;
  dp[0][0][0][0] = 1;
  for (int n = 0; n <= n1; n++)
    for (int m = 0; m <= n2; m++)
      for (int p = 0; p <= k1; p++)
	for (int q = 0; q <= k2; q++) {
	  if (p < k1) dp[n+1][m][p+1][0] = (dp[n+1][m][p+1][0] + dp[n][m][p][q])%mod;
	  if (q < k2) dp[n][m+1][0][q+1] = (dp[n][m+1][0][q+1] + dp[n][m][p][q])%mod;
	}
  int ans = 0;
  for (int p = 0; p <= k1; p++)
    for (int q = 0; q <= k2; q++)
      ans = (ans + dp[n1][n2][p][q])%mod;
  //  cout<<solve(0,0,0,0)<<endl;
  cout<<ans<<endl;
  return 0;
}
