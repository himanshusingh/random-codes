#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a); i>=int(b); i--)
typedef long long ll;
ll test, n, m;
ll a[111][111];

const ll mod = 1e9+7;


void col_operation(ll i, ll j) {
  ll x = a[i][j];
  FOR(k, i, n) {
    a[k][j] = ((a[i][i] * a[k][j])%mod - (x * a[k][i])%mod + mod)%mod;
  }
}
ll ppow(ll x, ll p, ll mod)
{
  ll ret = 1;
  while (p) {
    if (p&1) ret = (ret*x)%mod;
    x = (x*x)%mod;
    p /= 2;
  }
  return ret%mod;
}
ll determinant() {
  ll denominator = 1;
  ll numerator = 1;
  FOR(i, 1, n) if(!a[i][i]) return 0;
  FOR(i, 1, n) {
    FOR(j, i+1, n) {
     denominator = (denominator * a[i][i])%mod;
     col_operation(i,j);
    }
    numerator = (numerator * a[i][i])%mod;
    //numerator.print(); denominator.print();  printf("\n");
  }
  return (numerator*ppow(denominator, mod-2, mod) + mod)%mod;
}
int main()
{
  freopen("inp.in", "r", stdin);
  scanf ("%Ld", &test);
  while (test--) {
    scanf ("%Ld %Ld", &n, &m);
    for (ll i = 0; i <= n; i++) for (ll j = 0; j <= n; j++) a[i][j] = 0;
    for (ll i = 0; i < m; i++) {
      ll x, y;
      scanf ("%Ld %Ld", &x, &y);
   //   x++, y++;
      a[x][y] = a[y][x] = -1;
      a[x][x]++; a[y][y]++;
    }
    cout<<determinant()<<endl;
  }
  return 0;
}
