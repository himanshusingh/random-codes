#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int MAX_N = 5010;
vector< pair<int, int> > G[MAX_N];
pair<int, int> node[MAX_N];
vector<int> state[MAX_N], tmp[MAX_N];
int  pri[MAX_N];
int ans[MAX_N];
int n;
map<int, int> ptoi;
void input()
{
 cin>>n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin>>p;
    pri[i] = p;
    ptoi[p] = i;
  }
  for (int i = 1; i <= n-1; i++) {
    int a, b, c;
    cin>>a>>b>>c;
    G[a].push_back(make_pair(b,c));
    G[b].push_back(make_pair(a,c));
  }
}
void dfs(int x, int par)
{
  for (int i = 0; i < G[x].size(); i++) if (G[x][i].first != par) {
      node[G[x][i].first] = make_pair(x, G[x][i].second);
      dfs(G[x][i].first, x);
    }
}
void solve()
{
  dfs(1,0);
  for (int i = 2; i <= n; i++) state[i].push_back(pri[i]);
  for (int day = 1; day <= n; day++) {
    for (int i = 2; i <= n; i++) {
      int p = node[i].first, c = node[i].second;
      sort(state[i].begin(), state[i].end());
      for (int j = 0; j < state[i].size(); j++)
	if (j < c)
	  tmp[p].push_back(state[i][j]);
	else
	  tmp[i].push_back(state[i][j]);
    }
    for (int i = 1; i <= n; i++) state[i] = tmp[i], tmp[i].clear();
    for (int i = 0; i < state[1].size(); i++) ans[ptoi[state[1][i]]] = day;
    state[1].clear();
  }
}
int main()
{
  input();
  solve();
  for (int i = 1; i <= n; i++)
    cout<<ans[i]<<" ";cout<<endl;
  return 0;
}
