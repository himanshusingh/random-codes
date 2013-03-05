#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAX_N = 1e5+7;
ll perm[MAX_N];
ll m;
ll pow(ll x, ll n)
{
  ll y = 1;
  while (n) {
    if (n&1) y = (y*x)%m;
    x = (x*x)%m;
    n /= 2;
  }
  return y;
}
map< int, vector<int> > seq;
int a[2*MAX_N];
int main()
{
  int n;
  int dup;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    seq[a[i]].push_back(i);
  }
  dup = 0;
  for (int i = 1; i <= n; i++) {
    cin>>a[i+n];
    dup += (a[i]==a[i+n]);
    seq[a[i+n]].push_back(i);
  }
  cin>>m;
  perm[0] = 1;
  for (int i = 1; i < MAX_N; i++) perm[i] = (i*perm[i-1])%m;
  ll ans = 1;
  for (typeof(seq.begin()) it = seq.begin(); it != seq.end(); it++) {
    vector<int> v = it->second;
    for (int i = 1; i <= v.size(); i++) {
      int p = i;
      while (dup && (p%2 == 0)) p /= 2, dup--;
      ans = (ans*p)%m;
    }
  }
  cout<<ans<<endl;
  return 0;
}
