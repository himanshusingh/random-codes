#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAX_N = 128;
vector< pair<int, pair<ll, ll> > > G[MAX_N];
ll ans[MAX_N];
int vis[MAX_N], v;
ll gcd(ll a, ll b)
{
  return b?gcd(b,a%b):a;
}
bool dfs(int x)
{
  vis[x] = v;
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i].first;
    ll g = G[x][i].second.first, l = G[x][i].second.second;
    if (ans[x]%g || l%ans[x]) return false;
    if (vis[y] == v) {
      if (ans[x]*ans[y] != l*g || gcd(ans[x], ans[y]) != g) return false;
    } else {
      ans[y] = (l*g)/ans[x];
      if (gcd(ans[x], ans[y]) != g) return false;
      if(!dfs(y)) return false;
    }
  }
  return true;
}
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int a, b; ll g, l;
    cin>>a>>b>>g>>l;
    G[a].push_back(make_pair(b, make_pair(g,l)));
    G[b].push_back(make_pair(a, make_pair(g,l)));
    if (l%g) return cout<<"NO"<<endl, 0;
  }

  for (int i = 1; i <= n; i++) if (!ans[i]) {
      for (ans[i] = 1, v++; ans[i] <= 1000000 && !dfs(i); ans[i]++, v++);
      if (ans[i] > 1000000) return cout<<"NO"<<endl, 0;
    }
  cout<<"YES"<<endl;
  for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";cout<<endl;
  return 0;
}
