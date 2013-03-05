#include<iostream>
using namespace std;
const int oo = 1e7;
char G[111][10011];
int mind[111][10011];
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin>>G[i][j], mind[i][j] = oo, G[i][j] -= '0';
  bool ok = true;
  for (int r = 1; r <= n; r++) {
    int f = 0, l = 0;
    for (int c = 1; c <= m; c++) if (G[r][c]) {f = c; break;}
    for (int c = m; c >= 1; c--) if (G[r][c]) {l = c; break;}
    if (!f || !l) {ok = false; break;}
    for (int d = oo,c = 1; c <= m; c++)
      if (G[r][c]) mind[r][c] = d = 0;
      else mind[r][c] = min(mind[r][c], ++d);
    for (int d = oo, c = m; c >= 1; c--)
      if (G[r][c]) mind[r][c] = d = 0;
      else mind[r][c] = min(mind[r][c], ++d);

    for (int x = m-l, c = 1; c <= f; c++)
      mind[r][c] = min(mind[r][c], c + x);
    for (int x = f, c = l; c <= m; c++)
      mind[r][c] = min(mind[r][c], m-c+x);
  }
  int ans = oo;
  for (int c = 1; c <= m; c++) {
    int s = 0;
    for (int r = 1; r <= n; r++) s += mind[r][c];
    ans = min(s, ans);
  }
  if (ok)
    cout<<ans<<endl;
  else
    cout<<"-1"<<endl;
  return 0;
}
