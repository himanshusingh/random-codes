#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
char s[5001];
ll nck[5001][5001];
int main()
{
  int t;
  scanf ("%d", &t);
  for (int i = 0; i <= 5000; i++) {
    nck[i][0] = 1;
    for (int j = 1; j <= i; j++) nck[i][j] = (nck[i-1][j-1]+nck[i-1][j])%mod;
  }
  while (t--) {
    scanf ("%s", s);
    int n = strlen(s);
    int four = 0, seven = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) (s[i]=='4')?++four:++seven;
    // 7
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= min(i,four); j++) {
	int k = seven-(i-j)-1;
	if (j != k || k > n-i-1) continue;
	res = (res + (nck[i][j]*nck[n-i-1][j])%mod)%mod;
      }
    // 4
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= min(i,four-1); j++) {
	int k = seven-(i-j);
	if (j != k || k > n-i-1) continue;
	res = (res + (nck[i][j]*nck[n-i-1][j])%mod)%mod;
      }
    // 74
    for (int i = 0; i < n-1; i++)
      for (int j = 0; j <= min(i,four-1); j++) {
	int k = seven-(i-j)-1;
	if (j != k || k > n-i-2) continue;
	res = (res - (nck[i][j]*nck[n-i-2][j])%mod)%mod;
      }
    printf ("%Ld\n", (res+mod)%mod);
  }
  return 0;
}
