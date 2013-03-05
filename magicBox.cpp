#include<iostream>
using namespace std;
int x, y, z;
int X, Y, Z;
int a[7];
int main()
{
  cin>>x>>y>>z;
  cin>>X>>Y>>Z;
  for (int i = 1; i <= 6; i++) cin>>a[i];
  int ans = 0;
  if (x > X) ans += a[6];
  if (x < 0) ans += a[5];
  if (z > Z) ans += a[4];
  if (z < 0) ans += a[3];
  if (y > Y) ans += a[2];
  if (y < 0) ans += a[1];
  cout<<ans<<endl;
  return 0;
}
