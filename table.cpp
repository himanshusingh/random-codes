#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll powermod(ll x, ll p)
{
  ll y = 1;
  while (p) {
    if (p&1) y = (y*x)%mod;
    x = (x*x)%mod;
    p /= 2;
  }
  return y;
}
ll dp[101][10001];
ll ncr[101][101], ways[101][101];
int main()
{
  for (int i = 0; i <= 100; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j <= i; j++)
      ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%mod;
  }
  ll n, m, p;
  cin>>n>>m>>p;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int k = 0; k <= n; k++) ways[i][k] = powermod(ncr[n][k], m/n+(m%n >= i))%mod;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i*n && j <= p; j++)
      for (int k = 0; k <= n && k <= j; k++)
	dp[i][j] = (dp[i][j] + dp[i-1][j-k]*ways[i][k])%mod;
  cout<<dp[n][p]<<endl;
  return 0;
}
