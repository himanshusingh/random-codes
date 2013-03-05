#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int grid[1024][1024][2];
int c[1024][1024][2];
int n;
int countK(int num, int k)
{
  int cnt = 0;
  while (num%k == 0) {
    cnt++;
    num /= k;
  }
  return cnt;
}
int main()
{
  cin>>n;
  int zeroX = -1, zeroY = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      cin>>x;
      if (!x) zeroX = j, zeroY = i;
      else {
	c[i][j][0] = countK(x, 2);
	c[i][j][1] = countK(x, 5);
      }
    }
  for (int i = 1; i <= n; i++) for (int k = 0; k < 2; k++)grid[i][0][k] = grid[0][i][k] = 2e9;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
	if (i != 1 ||  j != 1)
	  grid[i][j][k] = min(grid[i-1][j][k], grid[i][j-1][k]);
	grid[i][j][k] += c[i][j][k];
      }
    }
  int d = 0;
  (grid[n][n][0] < grid[n][n][1])?(d=0):(d=1);
  int ans = grid[n][n][d];
  string path;
  int x = n, y = n;
  if (zeroX != -1 && ans >= 1) {
    ans = 1;
    for (; y > zeroY; y--) path += 'D';
    for (; x > 1; x--) path += 'R';
    for (; y > 1; y--) path += 'D';
  } else {
    while (x != 1 || y != 1) {
      if (grid[y][x - 1][d] + c[y][x][d] == grid[y][x][d]) {
	path += 'R';
	x--;
      } else {
	path += 'D';
	y--;
      }
    }
  }
  cout<<ans<<endl;
  reverse(path.begin(), path.end());
  cout<<path<<endl;      
  return 0;
}
