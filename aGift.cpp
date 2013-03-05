#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct road
{
	int from, to;
	int g, s;
	road(int f, int t, int _g, int _s): from(f), to(t), g(_g), s(_s)
	{}
	bool operator<(const road& r) const
	{
		return g < r.g;
	}
};

/* Disjoint set */
class disjointSet
{
	vector<int> parent;
public:
	disjointSet(int n)
	{
		parent.resize(n+1);
		for (int i = 0; i <= n; i++) parent[i] = i;
	}
	int find(int x)
	{
		return (parent[x] == x)?x:parent[x]=find(parent[x]);
	}

	int unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return -1;
		parent[x] = y;
		return 0;
	}
};

struct edge
{
	int from, to;
	int cost;
public:
	edge()
	{}
	edge(int f, int t, int c): from(f), to(t), cost(c)
	{}
	bool operator<(const edge& e) const
	{
		return cost < e.cost;
	}
};

int main()
{
//	freopen("in.in", "r", stdin);
	vector<road> roads;
	int N, M, G, S;
	cin>>N>>M;
	cin>>G>>S;
	for (int i = 1; i <= M; i++) {
		int f, t, g, s;
		cin>>f>>t>>g>>s;
		roads.push_back(road(f, t, g, s));
	}
	sort(roads.begin(), roads.end());
	long long ans = 1ll<<61;
	edge edges[N+1];
	int size = 0;
	for (int i = 0; i < roads.size(); i++) {
		int g = roads[i].g, s = roads[i].s;
		int from = roads[i].from, to = roads[i].to;
		if (from == to) continue;
		edges[size++] = edge(from, to, s);
		sort(edges, edges+size);
		disjointSet ds(N);
		int cycle = -1;
		for (int j = 0; j < size; j++) {
			int f = edges[j].from, t = edges[j].to;
			if (ds.find(f) == ds.find(t)) cycle = j;
			else ds.unite(f, t);
		}
		if (cycle != -1) {
			for (int j = cycle+1; j < size; j++)
				edges[j-1] = edges[j];
			--size;
		}
		if (size == N-1)
			ans = min(ans, G*1ll*g + S*1ll*edges[N-2].cost);
	}
	if (ans == 1ll<<61)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}