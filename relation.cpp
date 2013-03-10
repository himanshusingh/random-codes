#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAX_N=1e5+7;
int in[MAX_N];
vector<int> G[MAX_N];
bool vis[MAX_N];
int main()
{
//	freopen("in.in", "r", stdin);
	int n, m, k;
	scanf ("%d %d %d", &n,&m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		in[a]++;
		in[b]++;
	}
	queue<int> Q;
	for (int i = 0; i < n; i++) if (in[i] < k) Q.push(i), vis[i] = true;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int i = 0; i < G[x].size(); i++) {
			int y = G[x][i];
			if (--in[y] < k && !vis[y]) Q.push(y), vis[y] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) if (in[i] >= k) ans++;
	printf ("%d\n", ans);
	return 0;
}