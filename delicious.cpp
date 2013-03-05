#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll num[20];
bool used[10];
int dig[20];
ll calc(int d, bool f)
{
  ll ret = 0;
  if (d == 1) {
    for (int i = f; i <= dig[d]; i++) if (!used[i]) ret++;
    return ret;
  }
  ll h = dig[d];
  for (int i = f; i < h; i++) if (!used[i]) ret++;
  int c = 0;
  for (int i = 0; i < 10; i++) c += !used[i];
  c--;
  for (int i = 2; i <= d; i++, c--) ret *= c;
  if (used[h]) return ret;
  used[h] = true;
  ret += calc(d-1, false);
  return ret;
}
ll solve(ll x)
{
  if (!x) return 0;
  ll y = x;
  int d = 0;
  while (y) { ++d; dig[d] = y%10; y/=10; }
  ll ret = 0;
  for (int i = 1; i < d; i++) ret += num[i];
  if (d > 10) return ret;
  for (int i = 0; i < 10; i++) used[i] = false;
  ret += calc(d, true);
  return ret;
}
int main()
{
  for (int i = 1; i < 20; i++) num[i] = 9;
  for (int i = 1; i < 20; i++)
    for (int j = 1, d = 9; j < i; j++,d--) num[i] = num[i]*1ll*d;
  int tests;
  scanf ("%d", &tests);
  while (tests--) {
    ll L, R;
    scanf ("%Ld %Ld", &L, &R);
    printf ("%Ld\n", solve(R)-solve(L-1));
  }
  return 0;
}
