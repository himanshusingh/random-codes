#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll A[55][55];
int N, M;
ll csum[55][55][55], rsum[55][55][55];
void preprocess()
{
  for (int c = 1; c <= M; c++)
    for (int r = 1; r <= N; r++) csum[c][1][r] = csum[c][1][r-1]+A[r][c];

  for (int c = 1; c <= M; c++)
    for (int a = 1; a <= N; a++)
      for (int b = a; b <= N; b++) csum[c][a][b] = csum[c][1][b]-csum[c][1][a-1];

  for (int r = 1; r <= N; r++)
    for (int c = 1; c <= M; c++) rsum[r][1][c] = rsum[r][1][c-1]+A[r][c];
  for (int r = 1; r <= N; r++)
    for (int a = 1; a <= M; a++)
      for (int b = a; b <= M; b++) rsum[r][a][b] = rsum[r][1][b]-rsum[r][1][a-1];
}
ll dp[51][51][51][51][2];
ll solve(int l, int r, int u, int d, int t)
{
  if (l > r || u > d) {
    return 0;
  }
  ll &ret = dp[l][r][u][d][t];
  if (~ret) return ret;
  ret = 0;
  if (t) {
    ret = max(ret, solve(l,r,u+1,d,!t) + rsum[u][l][r]);
    ret = max(ret, solve(l,r,u,d-1,!t) + rsum[d][l][r]);
    ret = max(ret, solve(l+1,r,u,d,!t) + csum[l][u][d]);
    ret = max(ret, solve(l,r-1,u,d,!t) + csum[r][u][d]);
  } else {
    ll mn = min(csum[l][u][d],min(csum[r][u][d],min(rsum[u][l][r],rsum[d][l][r])));
    if (rsum[u][l][r] == mn) return ret = solve(l,r,u+1,d,!t);
    if (rsum[d][l][r] == mn) return ret = solve(l,r,u,d-1,!t);
    if (csum[l][u][d] == mn) return ret = solve(l+1,r,u,d,!t);
    if (csum[r][u][d] == mn) return ret = solve(l,r-1,u,d,!t);
  }
  return ret;
}
int main()
{
  int tests;
  scanf ("%d", &tests);
  while (tests--) {
    memset(dp, -1, sizeof(dp));
    memset(csum, 0, sizeof(csum));
    memset(rsum, 0, sizeof(rsum));
    scanf ("%d %d", &N, &M);
    ll sum = 0;
    for (int r = 1; r <= N; r++)
      for (int c = 1; c <= M; c++) scanf ("%Ld", &A[r][c]), sum += A[r][c];
    preprocess();
    ll bob = solve(1,M,1,N,0);
    if (2*bob < sum)
      printf ("%Ld\n", sum-bob);
    else if (2*bob == sum)
      printf ("%Ld\n", sum);
    else
      printf ("%Ld\n", bob);
  }
  return 0;
}
