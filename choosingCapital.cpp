#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = int(2e5)+7;
vector<pii> G[MAX_N];
int R[MAX_N], D[MAX_N], total, ans[MAX_N];
void dfs(int x, int par, int r, int d)
{
  R[x] = r, D[x] = d;
  for (int i = 0; i < G[x].size(); i++) if (G[x][i].first != par) {
      dfs(G[x][i].first, x, r + G[x][i].second, d+1);
      total += G[x][i].second;
    }
}
int main ()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n-1; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(pii(b,0));
    G[b].push_back(pii(a,1));
  }
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) ans[i] = total - 2*R[i] + D[i];
  int best = 1e9;
  vector<int> bestnodes;
  for (int i = 1; i <= n; i++) if (best > ans[i]) {
      best = ans[i];
      bestnodes.clear();
      bestnodes.push_back(i);
    } else if (best == ans[i]) {
      bestnodes.push_back(i);
    }
  cout<<best<<endl;
  for (int i = 0; i < bestnodes.size(); i++)
    cout<<bestnodes[i]<<" ";cout<<endl;
  return 0;
}
