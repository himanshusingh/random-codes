#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 2048;
vector<int> G[MAX_N];
int maxlen;
void dfs(int x, int len)
{
  maxlen = max(len, maxlen);
  for (int i = 0; i < G[x].size(); i++)
    dfs(G[x][i], len+1);
}
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin>>p;
    if (p == -1) p = 0;
    G[p].push_back(i);
  }
  dfs(0, 0);
  cout<<maxlen<<endl;
  return 0;
}
