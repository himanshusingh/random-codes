#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int abs(int x)
{
	return (x<0)?-x:x;
}
const int MAX_N = 1024;
int tests;
int dp[MAX_N][MAX_N];
int dp2[MAX_N];
int n;
int x[MAX_N], y[MAX_N], z[MAX_N];
int vis[MAX_N][MAX_N], vis2[MAX_N];
int iter;
int memo(int idx, int p, int use)
{
	iter++;
	if (idx >= n) return 0;
	int ret = 0;
	if (!use) {
		if (vis2[idx] == tests) return dp2[idx];
		vis2[idx] = tests;
		//if (~dp2[idx]) return dp2[idx];
		int dist = abs(x[idx]-x[idx+1]) + abs(y[idx]-y[idx+1]) + abs(z[idx]-z[idx+1]);
		ret = memo(idx+1, p, use) + dist;
		ret = min(ret, memo(idx+1, idx, 1));
		return dp2[idx] = ret;
	} else {
		if (vis[idx][p] == tests) return dp[idx][p];
		vis[idx][p] = tests;
		//if (~dp[idx][p]) return dp[idx][p];
		int dist = abs(x[idx]-x[idx+1]) + abs(y[idx]-y[idx+1]) + abs(z[idx]-z[idx+1]);
		int dist2 = abs(x[p]-x[idx+1]) + abs(y[p]-y[idx+1]) + abs(z[p]-z[idx+1]);
		ret = memo(idx+1, p, use) + dist;
		ret = min(ret, memo(idx+1, idx, use) + dist2);
		return dp[idx][p] = ret;
	}
}
int memo2(int idx, int p, int use)
{
	if (idx >= n) return 0;
	int ret = 0;
	if (!use) {
		if (vis[idx][0] == tests) return dp[idx][0];
		vis[idx][0] = tests;
		//if (~dp2[idx]) return dp2[idx];
		int dist = abs(x[idx]-x[idx+1]) + abs(y[idx]-y[idx+1]) + abs(z[idx]-z[idx+1]);
		ret = memo(idx+1, p, use) + dist;
		ret = min(ret, memo(idx+1, idx, 1));
		return dp[idx][0] = ret;
	} else {
		if (vis[idx][p] == tests) return dp[idx][p];
		vis[idx][p] = tests;
		//if (~dp[idx][p]) return dp[idx][p];
		int dist = abs(x[idx]-x[idx+1]) + abs(y[idx]-y[idx+1]) + abs(z[idx]-z[idx+1]);
		int dist2 = abs(x[p]-x[idx+1]) + abs(y[p]-y[idx+1]) + abs(z[p]-z[idx+1]);
		ret = memo(idx+1, p, use) + dist;
		ret = min(ret, memo(idx+1, idx, use) + dist2);
		return dp[idx][p] = ret;
	}
}
int main()
{
//	freopen("inp.in", "r", stdin);
	scanf ("%d", &tests);
	tests++;
	while (tests-- > 1) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) scanf ("%d %d %d", x+i, y+i, z+i);
		printf ("%d\n", memo2(1, 0, 0));
	}
	return 0;
}