#include <iostream>
#include <vector>
using namespace std;
int n;
int heights[1024];
int lft[1024], rht[1024];
int main ()
{
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>heights[i];
  for (int i = 1; i < n; i++)
    if (heights[i-1] <= heights[i]) lft[i] = lft[i-1] + 1;

  for (int i = n - 2; i >= 0; i--)
    if (heights[i + 1] <= heights[i]) rht[i] = rht[i+1] + 1;

  int ans = 0;
  for (int i = 0; i < n; i++)
    if (lft[i] + rht[i] + 1 > ans) ans = lft[i] + rht[i] + 1;
  cout<<ans<<endl;
  return 0;
}
