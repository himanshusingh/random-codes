#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long dp[2][5001];
long long a[5001], s[5001];
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i], s[i] = a[i];
  sort (s+1, s+n+1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j != 1)
	dp[1][j] = min(dp[1][j-1], abs(a[i]-s[j]) + dp[0][j]);
      else
	dp[1][j] = abs(a[i]-s[j]) + dp[0][j];
    }
    for (int j = 1; j <= n; j++) dp[0][j] = dp[1][j];
  }

  cout<<dp[1][n]<<endl;
  return 0;
}
