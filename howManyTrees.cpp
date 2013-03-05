#include<iostream>
#include<cstring>
using namespace std;
long long memo[36][36];
long long solve(int n, int h)
{
  if (h > n) return 0;
  if (!n && !h) return 1;
  if (h <= 0) return 0;
  if (~memo[n][h]) return memo[n][h];
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= h-2; j++) {
      ret += solve(i-1, j)*solve(n-i, h-1);
      ret += solve(i-1, h-1)*solve(n-i, j);
    }
    ret += solve(i-1,h-1)*solve(n-i, h-1);
  }
  return memo[n][h] = ret;
}
long long solve2(int n, int h)
{
  if (h == 0) return 0;
  if (n <= 1) return memo[n][h] = 1;
  if (~memo[n][h]) return memo[n][h];
  long long ret = 0;
  for (int i = 1; i <= n; i++) ret += solve2(i-1,h-1)*solve2(n-i,h-1);
  return memo[n][h] = ret;
}
int main()
{
  int n, h;
  cin>>n>>h;
  for (int i = 0; i < 36; i++) for (int j = 0; j < 36; j++) memo[i][j] = -1;
  long long ans = 0;
  for (int i = h; i <= n; i++) ans += solve(n,i);
  for (int i = 0; i < 36; i++) for (int j = 0; j < 36; j++) memo[i][j] = -1;
  ans = solve2(n,n) - solve2(n,h-1);
  cout<<ans<<endl;
  return 0;
}
