#include<iostream>
#include<cstring>
using namespace std;
long long x[100001];
long long dpL[100001][2], dpR[100001][2];
int n;
long long solveL(int i, int w)
{
  if (i == 0) return 0;
  if (~dpL[i][w]) return dpL[i][w];
  if (!w) {
    dpL[i][w] = max (x[i-1], max(solveL(i-1,0) + x[i-1] - !(x[i-1]%2), 
				solveL(i-1, 1) + x[i-1]));
  } else {
    if (x[i-1] > 1)
      dpL[i][w] = solveL(i-1,1) + x[i-1] - (x[i-1]%2);
    else
      dpL[i][w] = 0;
  }
  return dpL[i][w];
}
long long solveR(int i, int w)
{
  if (i == n-1) return 0;
  if (~dpR[i][w]) return dpR[i][w];
  if (!w) {
    dpR[i][w] = max(x[i], max(solveR(i+1,0) + x[i] - !(x[i]%2), solveR(i+1,1) + x[i]));
  } else {
    if (x[i] > 1)
      dpR[i][w] = solveR(i+1,1) + x[i] - (x[i]%2);
    else
      dpR[i][w] = 0;
  }
  return dpR[i][w];
}
int main()
{
  cin>>n;
  for (int i = 0; i < n-1; i++) cin>>x[i];
  long long best = 0;
  memset(dpL, -1, sizeof(dpL));
  memset(dpR, -1, sizeof(dpR));
  for (int i = 0; i < n; i++) {
    long long t =  max(solveL(i, 0), solveR(i,0));
    if (t > best) best = t;
    t = max(solveL(i, 1) + solveR(i,0), solveL(i,0) + solveR(i,1));
    if (t > best) best = t;
    t = solveL(i,1) + solveR(i,1);
    if (t > best) best = t;
  }
  cout<<best<<endl;
  return 0;
}
