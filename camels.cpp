#include<iostream>
using namespace std;
int dp[21][2][5][12][12];
int main()
{
  int points, humps;
  cin>>points>>humps;
  for (int h = 2; h <= 4; h++) dp[2][1][h][0][0] = h-1;
  for (int h = 1; h <= 3; h++) dp[2][0][h][0][0] = 4-h;

  for (int i = 2; i < points; i++)
    for (int t = 0; t <= humps; t++)
      for (int nt = 0; nt < humps; nt++) {
	for (int h = 2; h <= 4; h++)
	  for (int hh = 1; hh < h; hh++)
	    dp[i+1][0][hh][t+1][nt] += dp[i][1][h][t][nt];
	for (int h = 2; h <= 4; h++)
	  for (int hh = h+1; hh <= 4; hh++)
	    dp[i+1][1][hh][t][nt] += dp[i][1][h][t][nt];

	for (int h = 1; h <= 3; h++)
	  for (int hh = h+1; hh <= 4; hh++)
	    dp[i+1][1][hh][t][nt+1] += dp[i][0][h][t][nt];
	for (int h = 1; h <= 3; h++)
	  for (int hh = 1; hh < h; hh++)
	    dp[i+1][0][hh][t][nt] += dp[i][0][h][t][nt];
      }
  long long ans = 0;
  for (int h = 1; h <= 4; h++) ans += dp[points][0][h][humps][humps-1] + dp[points][1][h][humps][humps-1];
  cout<<ans<<endl;
}
