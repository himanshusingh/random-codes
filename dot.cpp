#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int dp[402][402][2][2][2]; // x, y, r1, r2, p
int n, dx[20], dy[20];
int d;
double dist(int x, int y)
{
  return sqrt((x-200)*(x-200) + (y-200)*(y-200));
}
int solve(int x, int y, int r1, int r2, int p)
{
  if (~dp[x][y][r1][r2][p]) return dp[x][y][r1][r2][p];
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (dist(x+dx[i] ,y+dy[i]) > (double)d) continue;
    ok |= (solve(x+dx[i], y+dy[i], r1, r2, !p) == p);
  }
  if (p && r2)
    ok |= (solve(y,x, r1, r2-1, !p) == p);
  else if (!p && r1)
    ok |= (solve(y, x, r1-1, r2, !p) == p);

  return dp[x][y][r1][r2][p] = ok?p:!p;
}
int main()
{
  int x, y;
  cin>>x>>y>>n>>d;
  x += 200, y += 200;
  for (int i = 0; i < n; i++)
    cin>>dx[i]>>dy[i];
  memset(dp, -1, sizeof(dp));
  if (solve(x, y, 1, 1, 0) == 0)
    cout<<"Anton"<<endl;
  else
    cout<<"Dasha"<<endl;
  return 0;
}
