#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1e4+7;
int parent[MAX_N];
int getp(int x)
{
	return (parent[x]  == x)?x:parent[x]=getp(parent[x]);
}
int main()
{

	int tests;
	scanf ("%d", &tests);
	while (tests--) {
		int n, m;
		int a, b, x;
		scanf ("%d %d", &n, &m);
		vector< pair<int, pair<int, int> > > edges;
		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &a, &b, &x);
			edges.push_back(make_pair(x, make_pair(a, b)));
		}
		sort(edges.begin(), edges.end());
		for (int i = 1; i <= n; i++) parent[i] = i;

		long long ans = 0;
		for (int e = 0; e < edges.size(); e++) {
			x = edges[e].first, a = edges[e].second.first, b = edges[e].second.second;
			a = getp(a), b = getp(b);
			if (a == b) continue;
			parent[a] = b;
			ans += x;
		}
		printf ("%Ld\n", ans);
	}
	return 0;
}