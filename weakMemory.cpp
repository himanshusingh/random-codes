#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX_N = int(1e5)+7;
bool vol[MAX_N];
int begin, end, n, m, k;
vector<int> G[MAX_N];
int w[MAX_N], in[MAX_N];
bool test(int t)
{
  queue<int> Q;
  for (int i = 1; i <= n; i++) {
    w[i] = t+1; in[i] = 0;
  }
  Q.push(begin);
  in[begin] = true;
  w[begin] = 0;
  while (!Q.empty()) {
    int p = Q.front(); Q.pop();
    in[p] = false;
    if (w[p] + 1 > t) continue;
    for (int i = 0; i < G[p].size(); i++) {
      int q = G[p][i], y = w[p]+1;
      if (q == end) return true;
      if (vol[q]) y = 0;
      if (w[q] <= y) continue;
      w[q] = y;
      if (!in[q]) Q.push(q), in[q] = true;
    }
  }
  return false;
}
int solve()
{
  int ret = n+1;
  int mi, lo = 1, hi = n + 1;
  while (lo <= hi) {
    mi = (lo + hi)/2;
    if (test(mi)) ret = mi, hi = mi - 1;
    else lo = mi + 1;
  }
  return ret;
}
int main()
{
  cin>>n>>m>>k;
  for (int i = 1; i <= k; i++) {
    int v; cin>>v;
    vol[v] = true;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin>>begin>>end;
  int ans = solve();
  if (ans == n+1)
    cout<<"-1"<<endl;
  else
    cout<<ans<<endl;
  return 0;
}
