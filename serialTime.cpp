#include<iostream>
using namespace std;
bool vis[11][11][11];
char G[11][11][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int k, n, m;
int dfs(int z, int x, int y)
{
  int cnt = 1;
  vis[z][x][y] = true;
  for (int d = 0; d < 4; d++) {
    int nx = x+dx[d], ny = y+dy[d];
    if (nx > 0 && ny > 0 && nx <= n && ny <= m && G[z][nx][ny] != '#' && !vis[z][nx][ny])
      cnt += dfs(z,nx,ny);
  }
  if (z > 1 && G[z-1][x][y] != '#' && !vis[z-1][x][y])
    cnt += dfs(z-1,x,y);
  if (z < k && G[z+1][x][y] != '#' && !vis[z+1][x][y])
    cnt += dfs(z+1,x,y);
  return cnt;
}
int main()
{

  cin>>k>>n>>m;
  for (int a = 1; a <= k; a++)
    for (int b = 1; b <= n; b++)
      for (int c = 1; c <= m; c++)
	cin>>G[a][b][c];
  int x, y;
  cin>>x>>y;
  cout<<dfs(1, x ,y)<<endl;
  return 0;
}
