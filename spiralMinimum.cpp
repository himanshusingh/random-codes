#include<iostream>
using namespace std;
int grid[512][512];
int sum[512][512];
int squareSum(int x, int y, int d)
{
  d--;
  return sum[x + d][y + d] + sum[x - 1][y - 1] - sum[x - 1][y + d] - sum[x + d][y - 1];
} 
int n, m;
int main()
{
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin>>grid[i][j];
      sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  int ans = -(1<<29);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int maxd = min(min(i - 1, n - i), min(j - 1, m - j));
      int spiral = grid[i][j];
      for (int d = 1; d <= maxd; d++) {
	spiral = squareSum(i - d, j - d, 2*d + 1) - spiral - grid[i - d + 1][j - d];
	ans = max(ans, spiral);
      }
    }
  cout<<ans<<endl;
  return 0;
}
