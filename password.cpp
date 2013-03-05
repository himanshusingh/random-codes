#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int Z[1000010];
char str[1000010];
void zline(char *str)
{
  int n = strlen(str);
  for (int l = 0, r = 0, i = 1; i < n; i++) {
    if (i <= r)
      Z[i] = min(r - i + 1, Z[i - l]);
    while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]]) Z[i]++;
    if (i + Z[i] - 1 > r) l = i, r = i + Z[i] -1;
  }
}

int main()
{
  cin>>str;
  zline(str);
  int maxz = 0;
  int n = strlen(str);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (Z[i] == n - i && Z[i] <= maxz) { ans = Z[i]; break; }
    maxz = max(maxz, Z[i]);
  }
  str[ans] = 0;
  if (!ans)
    cout<<"Just a legend"<<endl;
  else
    cout<<str<<endl;
  return 0;
}

