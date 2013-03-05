#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll a, b;
ll matrix[20][20];
ll res[20][20], tmp[20][20];
void mul(int n, bool f)
{
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) tmp[i][j] = 0;
  if (f) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++)
	  tmp[i][j] = (tmp[i][j] + (res[i][k]*matrix[k][j])%mod)%mod;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) res[i][j] = tmp[i][j];
  } else {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++)
	  tmp[i][j] = (tmp[i][j] + (matrix[i][k]*matrix[k][j])%mod)%mod;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) matrix[i][j] = tmp[i][j];
  }
}
void raise(int n, ll p)
{
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) res[i][j] = i==j;
  while (p) {
    if (p&1) mul(n, 1);
    mul(n,0);
    p /= 2;
  }
}

ll x1[] = {1,2};
ll x2[] = {2,4,14};
ll x3[] = {3,8,50,322};
ll x4[] = {5,16,178,2066,23858,275690};
ll x5[] = {9,32,634,13262,275690,5735478,119310334ll,2481942354ll,630302833,33293940};
ll x6[] = {18,
	   64,
	   2258,
	   85126,
	   3185462,
	   119310334,
	   468252386,
	   341333373,
	   120424565,
	   733930200,
	   669210003,
	   533541711,
	   486842637,
	   54569745,
	   550722139,
	   438338918,
	   88893786,
	   394456513,
	   927568251,
};
ll* xs[] = {0, x1,x2,x3,x4,x5,x6};

ll m1[] = {1, 2};
ll m2[] = {2,3,2};
ll m3[] = {3,6,3,-2};
ll m4[] = {5,10,20,-21,-30,8};
ll m5[] = {9,21,9,-278,73,790,-662,29,69,-10};
ll m6[] = {18,36,120,-2391,-3905,50702,27152,-396016,154999,751787,-499260,-410368,355981,38077,-70276,6203,3386,-622,28};
ll* ms[] = {0, m1,m2,m3,m4,m5,m6};
int main()
{
  scanf ("%Ld %Ld", &a, &b);
  int n = xs[a][0];
  if (b <= n)
    printf ("%Ld\n", xs[a][b]%mod);
  else {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) matrix[i][j] = 0;
    for (int i = 1; i <= n; i++) matrix[1][i] = ms[a][i];
    for (int i = 2; i <= n; i++) matrix[i][i-1] = 1;
    raise(n,b-n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + (xs[a][n-i+1]*res[1][i])%mod)%mod;
    ans = (ans + mod)%mod;
    printf ("%Ld\n", ans%mod);
  }
  return 0;
}
