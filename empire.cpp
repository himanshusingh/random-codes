#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int oo = 1e9;
int n, m, p, cap;
bool station[333];
vector<int> G[333];
int dist[333];
int shp[333][333];
bool vis[333];
int main()
{
//	freopen("in.in", "r", stdin);
	scanf ("%d %d %d %d", &n, &m, &p, &cap);
	for (int i = 0; i < p; i++) {
		int s; scanf ("%d", &s);
		station[s] = true;
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) if (i != j) shp[i][j] = oo;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf ("%d %d %d", &a, &b, &t);
		shp[a][b] = t;
		shp[b][a] = t;
	}
	if (n == 1) {
		printf ("0\n");
		return 0;
	}
	if (!station[0]) {
		printf ("-1\n");
		return 0;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) shp[i][j] = min(shp[i][j], shp[i][k] + shp[k][j]);
	queue< pair<int, int> > Q;
	Q.push(make_pair(0, 0));
	for (int i = 0; i <= n; i++) dist[i] = oo;
	dist[0] = 0;
	vis[0] = true;
	while (!Q.empty()) {
		int v = Q.front().first, d = Q.front().second; Q.pop();
		if (shp[v][n-1] <= cap) dist[n-1] = min(dist[n-1], shp[v][n-1] + d);
		else {
			for (int i = 0; i < n; i++)
				if (i != v && station[i] && !vis[i] && shp[v][i] <= cap)
					Q.push(make_pair(i, d + shp[v][i])), vis[i] = true;
		}
	}

	if (dist[n-1] != oo) printf ("%d\n", dist[n-1]);
	else printf ("-1\n");
	return 0;
}

