#include<iostream>
using namespace std;
const int MAX_N = 2000;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
char G[MAX_N][MAX_N];
int px[MAX_N][MAX_N], py[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int n, m;

bool memo(int X, int Y)
{
  int x = (X%n + n)%n, y = (Y%m + m)%m;
  if (G[x][y] == '#') return false;
  if (vis[x][y]) return X != px[x][y] || Y != py[x][y];
  vis[x][y] = true;
  px[x][y] = X, py[x][y] = Y;
  bool ret = false;
  for (int d = 0; d < 4; d++) {
    int xx = X + dx[d], yy = Y + dy[d];
    ret |= memo(xx, yy);
  }
  return ret;
}
int main()
{
  cin>>n>>m;
  for (int i = 0; i < n; i++) cin>>G[i];
  bool ok = false;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) if (G[i][j] == 'S') { ok  = memo(i, j); break; }
  if (ok)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
