#include<iostream>
using namespace std;
char G[2048][2048];
int rr[2048], cr[2048], rl[2048], cl[2048];
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>G[i] + 1;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = n; j > i; j--)
      if ((G[i][j]-'0')^rr[i]^cr[j]) ++ans, rr[i]^=1, cr[j]^=1;

  for (int i = n; i >= 1; i--)
    for (int j = 1; j < i; j++)
      if ((G[i][j]-'0')^rl[i]^cl[j]) ++ans, rl[i]^=1, cl[j]^=1;

  for (int i = 1; i <= n; i++)
    if ((G[i][i]-'0')^rl[i]^cl[i]^rr[i]^cr[i]) ++ans;

  cout<<ans<<endl;
  return 0;
}
