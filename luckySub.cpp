#include<iostream>
#include<map>
using namespace std;
const int mod = 1e9+7;
int a[100001];
bool islucky(int n)
{
  bool ok = true;
  while (n) {
    if (n%10 != 7 && n%10 != 4) ok = false;
    n /= 10;
  }
  return ok;
}
long long inverse(long long a, long long m)
{
  long long p = 1, y = m - 2;
  long long x = a;
  while (y) {
    if (y&1) p = (p*x)%m;
    x = (x*x)%m;
    y /= 2;
  }
  return (p+m)%m;
}
long long fact[100001];
long long Cr(long long n, long long r, long long m)
{
  if (n < r) return 0;
  if (!r || n == r) return 1;
  return ((fact[n]*inverse(fact[r], m)%m)*inverse(fact[n-r], m)%m + m)%m;
}
void preprocess()
{
  fact[0] = 1;
  for (int i = 1; i <= 100000; i++)
    fact[i] = (i*fact[i-1])%mod;
}

map<int, int> lucky;
long long dp[1024][1024];
int main()
{
  int n, k;
  preprocess();
  cin>>n>>k;
  int un = 0;
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    if (islucky(a[i])) lucky[a[i]]++;
    else un++;
  }
  map<int,int>::iterator it;
  int l = 0;
  dp[0][0] = 1;
  for (it = lucky.begin(), l = 1; it != lucky.end(); it++, l++) {
    for (int j = 0; j <= l; j++) {
      dp[l][j] = (dp[l-1][j] + (j?dp[l-1][j-1]*(it->second):0))%mod;
    } 
  }
  l--;
  
  long long ans = 0;
  for (int i = 0; i <= k; i++) if (i <= l) {
      ans = (ans + (Cr(un, k-i, mod)%mod)*dp[l][i]%mod)%mod;
    }
  ans = (ans + mod)%mod;
  cout<<ans<<endl;
  return 0;
}
