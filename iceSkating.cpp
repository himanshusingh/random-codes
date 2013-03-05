#include<iostream>
using namespace std;
int f[110];
int find(int x)
{
  return (x==f[x])?x:f[x]=find(f[x]);
}
int x[110], y[110];
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= n; i++) cin>>x[i]>>y[i];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) if (x[i] == x[j] || y[i] == y[j]) {
	f[find(i)] = find(j);
      }
  int ans = 0;
  for (int i = 1; i <= n; i++) if (f[i] == i) ++ans;
  cout<<ans-1<<endl;
  return 0;
}
