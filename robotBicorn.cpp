#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
using namespace std;

int main()
{
  string str, a, b, c;
  cin>>str;
  int len = str.size();
  long long ans = 0;
  bool flag = 0;

  for (int i = 1; i <= len - 2; i++)
    for (int j = i + 1; j < len; j++) {
      a = str.substr(0, i);
      b = str.substr(i, j - i);
      c = str.substr(j);
      if ((a.size() != 1 && a[0] == '0') || (b.size() != 1 && b[0] == '0') || (c.size() != 1 && c[0] == '0')) continue;
      long long na = atol(a.c_str()), nb = atol(b.c_str()), nc = atol(c.c_str());
      if (a.size() > 7 || b.size() > 7 || c.size() > 7) continue;
      if (na > 1000000 || nb > 1000000 || nc > 1000000) continue;
      flag = 1;
      ans = max(ans, na + nb + nc);
    }
  if (flag)
    cout<<ans<<endl;
  else
    cout<<"-1"<<endl;
  return 0;
}
