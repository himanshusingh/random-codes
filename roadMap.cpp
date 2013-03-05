#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = int(5e4)+7;
vector<int> G[MAX_N];
int n, r1, r2;
int par[MAX_N];
void dfs(int x, int p)
{
  par[x] = p;
  for (int i = 0; i < G[x].size(); i++) if (G[x][i] != p) {
      dfs(G[x][i], x);
    }
}
int main()
{
  cin>>n>>r1>>r2;
  for (int i = 1; i <= n; i++) if (i != r1) {
    int p;
    cin>>p;
    G[i].push_back(p);
    G[p].push_back(i);
    }
  dfs(r2, 0);
  for (int i = 1; i <= n; i++)
    if (i != r2)
      cout<<par[i]<<" "; cout<<endl;
  return 0;
}
