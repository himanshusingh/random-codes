#include <iostream>
#include <string>
using namespace std;

void zline(int z[], string& str)
{
  z[0] = 0;
  int l, r;
  for (int i = 1, l = 0, r = 0; i < str.size(); i++) {
    if (i <= r)
      z[i] = min(r-i+1, z[i-l]);
    while ((i + z[i] < str.size()) && (str[z[i]] == str[i + z[i]])) z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
}

int za[100001], zb[100001];

int main()
{
  string a, b;
  cin>>a;
  cin>>b;
  int na = a.size(), nb = b.size();
  int n = min(a.size(), b.size());
  zline(za, a);
  zline(zb, b);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) break;
    if ((na%(i+1)) || (nb%(i+1))) continue;
    if ((i + 1 + za[i + 1] == na) && (i + 1 + zb[i + 1] == nb)) ans++;
  }    
  cout<<ans<<endl;
  return 0;
}
