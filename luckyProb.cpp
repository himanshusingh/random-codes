#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const long long oo = 1e9;
vector<long long> lucky;
void dfs(long long x)
{
  if (x > oo) return;
  lucky.push_back(x);
  dfs(x*10 + 4);
  dfs(x*10 + 7);
}
long long overlap(long long a, long long b, long long x, long long y)
{
  long long l = max(a, x);
  long long r = min(b, y);
  if (r < l) return 0;
  return r - l + 1;
}
long long pl, pr, vl, vr, k;
int main()
{
  cin>>pl>>pr>>vl>>vr>>k;
  dfs(0);
  sort(lucky.begin(), lucky.end());
  int n = lucky.size();
  lucky.push_back(oo);
  double ans = 0;
  for (int i = 1; i + k - 1 < n; i++) {
    long long ll = lucky[i-1]+1, lr = lucky[i];
    long long rl = lucky[i+k-1], rr = lucky[i+k]-1;
    long long p1 = overlap(pl, pr, ll, lr)*(long long)overlap(vl, vr, rl, rr);
    long long p2 = overlap(pl, pr, rl, rr)*(long long)overlap(vl, vr, ll, lr);
    ans += p1 + p2;
    if (p1 && p2) ans -= (k==1);
  }
  printf ("%.12lf\n", ans/double(pr-pl+1)/double(vr-vl+1));
  return 0;
}
