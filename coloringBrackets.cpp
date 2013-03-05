#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
long long dp[1024][1024][3][3];
int ob[1024];
const int mod = 1000000007;
long long memo(int x, int y, int p, int q)
{
  long long &res = dp[x][y][p][q];
  if (res != -1) return res;
  res = 0;
  if (ob[x] == y) {
    if (!(!p)^(!q)) res = 0;
    else if (x + 1 == y) res = 1;
    else {
      for (int i = 0; i < 3; i++) if (!p || i != p) {
	  for (int j = 0; j < 3; j++) if (!q || j != q) {
	      res = (res + memo(x+1, y-1, i, j))%mod;
	    }
	}
    }				    
  } else {
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) if (!i || i != j) {
	    res = (res + (long long)memo(x, ob[x], p, i)*(long long)memo(ob[x] + 1, y, j, q))%mod;
	  }
      }
  }
  return res;
}
int stack[1024];
int main()
{
  memset(dp, -1, sizeof(dp));
  string str;
  cin>>str;
  int cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') stack[cnt++] = i;
    else ob[stack[--cnt]] = i;
  }
  long long ans = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
	ans = (ans + memo(0, str.size()-1, i, j))%mod;
      }
  cout<<ans<<endl;
  return 0;
}
