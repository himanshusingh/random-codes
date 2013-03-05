#include<iostream>
using namespace std;
int G[101][101];
int seq[101];
int f[101];
int find(int x)
{
  return (x == f[x])?x:f[x] = find(f[x]);
}
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= n; i++) cin>>seq[i];
  for (int i = 1; i <= n; i++) {
    int d;
    cin>>d;
    if (i-d >= 1) G[i][i-d] = G[i-d][i] = 1;
    if (i+d <= n) G[i][i+d] = G[i+d][i] = 1;
  }
  for(int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	G[i][j] |= (G[i][k] & G[k][j]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) if (G[i][j]) f[i] = find(j);

  bool ok = true;
  for (int i = 1; i <= n; i++)
    if (find(seq[i]) != find(i)) ok = false;

  if (ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
