#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int MAX_N = 1e5+7;
typedef long long ll;
const ll oo = 1e17;
vector<int> G[MAX_N];
int n;
ll v[MAX_N];
ll moves;
pair<ll,ll> dfs(int x, int p)
{
  vector<ll> req;
  ll mo = v[x];
  ll mp = 0, mn = 0;
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i];
    if (y == p) continue;
    pair<ll,ll> ret = dfs(y, x);
    mp = max(mp, ret.first);
    mn = max(mn, ret.second);
  }
  if (mn == -oo) mn = 0;
  mo += mp - mn;
  if (mo >= 0) mn += mo;
  else mp += -mo;
  return make_pair(mp,mn);
}
int main()
{
  cin>>n;
  for (int i = 1; i <= n-1; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) cin>>v[i];
  pair<ll, ll> ret = dfs(1, 0);
  cout<<ret.first + ret.second<<endl;
  return 0;
}
