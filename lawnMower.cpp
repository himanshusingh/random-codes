#include<iostream>
#include<string>
using namespace std;

int grid[152][152];
int l[152], r[152];
int n, m;
int main()
{
  cin>>n>>m;
  string str;
  for (int i = 1; i <= n; i++) {
    cin>>str;
    for (int j = 0; j < m; j++)
      grid[i][j + 1] = (str[j] == 'W');
  }
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = 1; j <= m; j++) if (grid[i][j]) break;
    l[i] = j;
    for (j = m; j >= 1; j--) if (grid[i][j]) break;
    r[i] = j;
  }
  while (r[n] == 0) n--;

  int ans = 0;
  int p = 1;
  l[n + 1] = m + 1;
  r[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    if (i&1) {
      for (; p < r[i]; p++) ++ans;
      while (p < r[i + 1]) { ++p; ++ans; }
    } else {
      for (; p > l[i]; p--) ++ans;
      while (p > l[i + 1]) { --p; ++ans; }
    }
    if (i != n)
      ans++;
  }
  cout<<ans<<endl;
  return 0;
}
