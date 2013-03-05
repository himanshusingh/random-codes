#include<iostream>
using namespace std;
const long long oo = 100000000000000ll;
long long dp[4020];
struct item
{
  int t;
  long long c;
}items[2020];
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>items[i].t>>items[i].c;
    items[i].t++;
  }
  for (int i = 1; i <= 4000; i++) dp[i] = oo;

  for (int i = 1; i <= n; i++)
    for (int j = 4000; j >= items[i].t; j--)
      dp[j] = min(dp[j], dp[j-items[i].t] + items[i].c);
  long long ans = oo;
  for (int i = n; i <= 4000; i ++) ans = min(ans, dp[i]);
  cout<<ans<<endl;
}
