#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 1e5+7;
const int mod = 1e9+7;
int a[MAX_N], cum[MAX_N];
long long pow(int x, int p)
{
  long long ret = 1;
  while (p) {
    if (p&1) ret = (1ll*ret*x)%mod;
    x = (1ll*x*x)%mod;
    p /= 2;
  }
  return ret;
}
vector<int> fact[MAX_N];
int main()
{
  int n;
  cin>>n;
  int maxa = 0;
  for (int i = 1; i <= n; i++) cin>>a[i], maxa = max(maxa, a[i]), cum[a[i]]++;
  for (int i = 1; i <= maxa; i++) cum[i] += cum[i-1];
  long long ans = 0;
  for (int i = 1; i <= maxa; i++)
    for (int j = i; j <= maxa; j += i) fact[j].push_back(i);
  for (int i = 1; i <= maxa; i++) {
    int seen = 0;
    long long tmp = 1;
    for (int j = 0; j < fact[i].size(); j++) {
      int t = cum[fact[i][j]-1];
      tmp = (tmp*pow(j, t-seen))%mod;
      seen = t;
    }
    int rem = n-seen;
    tmp = (tmp*(pow(fact[i].size(), rem) - pow(fact[i].size()-1, rem) + mod)%mod)%mod;
    ans = (ans + tmp)%mod;
  }
  ans = (ans + mod)%mod;
  cout<<ans<<endl;
  return 0;
}
