#include<iostream>
#include<cstdio>
#include<set>
const int MAX_N = int(3e5)+7;
int lvl[MAX_N];
bool lft[MAX_N], rght[MAX_N];
using namespace std;
int n, x;
int main()
{
  scanf ("%d", &n);
  set<int> seq;
  scanf ("%d", &x);
  printf ("%d\n", 0);
  lvl[x] = 0;
  seq.insert(x);
  long long ans = 0;
  int pre, suc;
  for (int i = 0; i < n-1; i++) {
    scanf ("%d", &x);
    set<int>::iterator it = seq.upper_bound(x);
    pre = suc = 0;
    if (it != seq.end()) suc = *it;
    if (it != seq.begin()) pre = *(--it);
    if (pre && suc) {
      if (rght[pre]) {
	lft[suc] = true;
	lvl[x] = lvl[suc] + 1;
	ans += lvl[x];
      } else {
	rght[pre] = true;
	lvl[x] = lvl[pre] + 1;
	ans += lvl[x];
      }
    } else if (pre) {
      	rght[pre] = true;
	lvl[x] = lvl[pre] + 1;
	ans += lvl[x];
    } else {
	lft[suc] = true;
	lvl[x] = lvl[suc] + 1;
	ans += lvl[x];
    }
    seq.insert(x);
    printf ("%Ld\n", ans);
  }
}
