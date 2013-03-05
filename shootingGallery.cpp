#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int x[1024], y[1024], t[1024];
double p[1024];
bool G[1024][1024];
double res[1024];
bool reach(int i, int j)
{
  return (t[j] - t[i] >= sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
}
int n;
int main()
{
  cin>>n;
  for (int i = 1; i <= n; i++)
    cin>>x[i]>>y[i]>>t[i]>>p[i];

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (t[j] < t[i]) {
	swap(x[i], x[j]); swap(y[i], y[j]);
	swap(t[i], t[j]); swap(p[i], p[j]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = i - 1; j > 0; j--) if (reach(j, i)) G[j][i] = true;

  for (int i = 1; i <= n; i++) {
    res[i] = p[i];
    for (int j = i - 1; j > 0; j--) if (G[j][i] && (res[j] + p[i] > res[i])) {
	res[i] = res[j] + p[i];
      }
  }
  double ans = 0.0;
  for (int i = 1; i <= n; i++) if (res[i] > ans) ans = res[i];
  printf ("%.9f\n", ans);
  return 0;
}
