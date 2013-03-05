#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N = 5e5 + 7;
int c0[MAX_N], c1[MAX_N], r0[MAX_N], r1[MAX_N];
void update(int *arr, int idx, int v)
{
  for (int i = idx; i < MAX_N; i += (i&-i)) arr[i] += v;
}
int getcnt(int *arr, int idx)
{
  int ret = 0;
  for (int i = idx; i; i -= (i&-i)) ret += arr[i];
  return ret;
}
bool col[MAX_N], row[MAX_N];
int upc0[MAX_N], upc1[MAX_N], upr0[MAX_N], upr1[MAX_N];
int main()
{
  int n, q;
  cin>>n>>q;
  char query[20];
  int idx, x;
  int ans;
  for (int i = 1; i <= n; i++) upc0[i] = upr0[i] = q+1, upc1[i] = upr1[i] = q+2;
  for (int i = 1; i <= n; i++) { update(c0, q+1, 1); update(r0, q+1, 1); }
  for (int t = q; t >= 1; t--) {
    scanf ("%s", query);
    if (query[0] == 'R') {
      if (query[3] == 'Q') {
	scanf ("%d", &idx);
	if (row[idx]) ans = getcnt(c0, upr1[idx]);
	else ans = n - getcnt(c1, upr0[idx]);
	printf ("%d\n", ans);
      } else {
	scanf ("%d %d", &idx, &x);
	if (upr0[idx] < upr1[idx]) update(r0, upr0[idx], -1);
	else update(r1, upr1[idx], -1);
	if (x) {
	  upr1[idx] = t;
	  update(r1, upr1[idx], 1);
	  row[idx] = 1;
	} else {
	  upr0[idx] = t;
	  update(r0, upr0[idx], 1);
	  row[idx] = 0;
	}
      }
    } else {
      if (query[3] == 'Q') {
	scanf ("%d", &idx);
	if (col[idx]) ans = getcnt(r0, upc1[idx]);
	else ans = n - getcnt(r1, upc0[idx]);
	printf ("%d\n", ans);
      } else {
	scanf ("%d %d", &idx, &x);
	if (upc0[idx] < upc1[idx]) update(c0, upc0[idx], -1);
	else update(c1, upc1[idx], -1);
	if (x) {
	  upc1[idx] = t;
	  update(c1, upc1[idx], 1);
	  col[idx] = 1;
	} else {
	  upc0[idx] = t;
	  update(c0, upc0[idx], 1);
	  col[idx] = 0;
	}
      }
    }
  }
  return 0;
}
