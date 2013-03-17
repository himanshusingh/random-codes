#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 1e5+7;
vector<int> G[MAX_N], GR[MAX_N];
int s[MAX_N];
bool v[MAX_N], vr[MAX_N];
void dfs(int x)
{
  v[x] = true;
  for (int i = 0; i < G[x].size(); i++) if (!v[G[x][i]])
    dfs(G[x][i]);
}
void rdfs(int x)
{
  vr[x] = true;
  if (s[x] == 1) return;
  for (int i = 0; i < GR[x].size(); i++) if (!vr[GR[x][i]])
    rdfs(GR[x][i]);
}
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++) cin>>s[i];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    GR[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) if (!v[i] && (s[i] == 1)) dfs(i);
  for (int i = 1; i <= n; i++) if (!vr[i] && (s[i] == 2)) rdfs(i);
  for (int i = 1; i <= n; i++) (v[i]&&vr[i])?(cout<<"1"<<endl):(cout<<"0"<<endl);
  return 0;
}




