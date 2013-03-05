#include<iostream>
using namespace std;
int moves[8][10][10];
int dx[] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {1, 0, 0, -1, 0, 1, -1, -1, 1};
bool ok;
void dfs(int m, int px, int py)
{
  if (ok) return;
  if (m > 7) { ok = true; return; }
  for (int d = 0; d < 9; d++) {
    int x = px + dx[d], y = py + dy[d];
    if (x < 1 || x > 8 || y < 1 || y > 8) continue;
    if (moves[m][x][y] || moves[m+1][x][y]) continue;
    dfs(m+1, x, y);
  }
}
int main()
{
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) {
      char c;
      cin>>c;
      moves[0][i][j] = (c=='S');
    }
  for (int m = 1; m < 8; m++) 
    for (int i = 8; i > 0; i--)
      for (int j = 1; j <= 8; j++)
	moves[m][i][j] = moves[m-1][i-1][j];
  dfs(0, 8, 1);
  if (ok) cout<<"WIN"<<endl;
  else cout<<"LOSE"<<endl;
}
