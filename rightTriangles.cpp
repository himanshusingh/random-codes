#include<iostream>
using namespace std;

int G[1024][1024], row[1024], col[1024];
int n, m;
int main()
{
  cin>>n>>m;
  char c;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin>>c;
      G[i][j] = (c =='*');
    }
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) row[r] += G[r][c], col[c] += G[r][c];
  long long ans = 0;
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) if (G[r][c]) {
	ans += (row[r] - 1)*(col[c] -1);
      }

  cout<<ans<<endl;
  return 0;    
}
