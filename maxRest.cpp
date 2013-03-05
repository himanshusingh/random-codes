#include<iostream>
#include<cstring>
using namespace std;
int a[51];
double dp[51][101];
int main()
{
  int n, p;
  cin>>n;
  int sum = 0;
  for (int i = 1; i <= n; i++) cin>>a[i], sum += a[i];
  cin>>p;
  if (sum <= p) {
    cout<<n<<endl;
    return 0;
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.0;
    for (int j = 1; j <= n; j++) if (i != j)
      for (int c = n-1; c >= 0; c--)
	for (int s = p; s >= 0; s--)
	    dp[c+1][s+a[j]] += dp[c][s];
    for (int c = 0; c <= n; c++)
      for (int s = p-a[i]+1; s <= p; s++) {
	double perm = 1;
	for (int f = 1; f <= c; f++) perm *= f;
	for (int f = 1; f <= n-c-1; f++) perm *= f;
	ans += perm*dp[c][s]*c;
      }
  }
  for (int i = 1; i <= n; i++) ans /= (1.0*i);
  cout<<ans<<endl;
  return 0;
}
