#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 3e6+7;
int parent[MAX_N];
long long last[MAX_N];
int getp(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = getp(parent[x]);
}
pair< long long, pair<int, int> > edges[2*MAX_N];
int main()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		scanf ("%d %d %Ld", &a, &b, &c);
		a++, b++;
		edges[i] = (make_pair(c, make_pair(a, b)));
	}
	for (int i = 0; i <= n+1; i++) parent[i] = i;
	sort(edges, edges+m);
	for (int e = 0; e < m; e++) {
		long long c = edges[e].first;
		int a = edges[e].second.first, b = edges[e].second.second;
		a = getp(a), b = getp(b);
		if (a != b) {
			parent[a] = b;
			last[b] = c;
		} else {
			if (last[a] == c) {
				printf ("NO\n");
				return 0;
			}
		}
	}
	printf ("YES\n");
	return 0;
}