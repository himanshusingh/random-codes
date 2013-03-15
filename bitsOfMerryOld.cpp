/* Problem Link: http://www.codeforces.com/problemset/problem/132/E */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int oo = 1e9+7;
const int MAX_N = 1000;
const int MAX_E = 2*MAX_N*MAX_N;
int cost[MAX_E], cap[MAX_E];
int cap2[MAX_N][MAX_N];
int last[MAX_N], next[MAX_E];
int to[MAX_E];
int edges;
void add_edge(int f, int t, int c, int w)
{
	cost[edges] = w, cap[edges] = c;
	cap2[f][t] = c;
	to[edges] = t;
	next[edges] = last[f];
	last[f] = edges++;
	// reverse edge
	cost[edges] = -w, cap[edges] = 0;
	to[edges] = f;
	next[edges] = last[t];
	last[t] = edges++;
}
int ped[MAX_N], pre[MAX_N];
int spfa(int nodes, int s, int t)
{
    vector<int> dist(nodes+1, oo);
    queue<int> Q;
    vector<bool> in(nodes+1, false);
    Q.push(s); in[s] = true; dist[s] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop(); in[x] = false;
        for (int e = last[x]; e != -1; e = next[e]) if (cap[e] > 0) {
            int u = to[e^1], v = to[e];
            if (dist[v] > dist[u] + cost[e]) {
                dist[v] = dist[u] + cost[e];
                ped[v] = e;
                pre[v] = u;
                if (!in[v]) Q.push(v), in[v] = true;
            }
        }
    }
    return dist[t];
}

pair<int, int> minCostMaxFlow(int nodes, int s, int t)
{
    int flow = 0;
    int d, ret = 0;
    while ((d = spfa(nodes, s, t)) + 7 < oo) {
        int minf = oo;
        for (int i = t; i != s; i = pre[i]) minf = min(minf, cap[ped[i]]);
            for (int i = t; i != s; i = pre[i]) {
                cap[ped[i]] -= minf;
                cap[ped[i]^1] += minf;
                int e = ped[i];
                cap2[to[e^1]][to[e]] -= minf;
                cap2[to[e]][to[e^1]] += minf;
            }
            flow += minf;
            ret += d*minf;
    }
    return make_pair(flow, ret);
}
int n , m;
int seq[MAX_N];
int bit[MAX_N];
bool change[MAX_N];
int var[MAX_N];
int main()
{
	cin>>n>>m;
	for (int i = 1; i <= n; i++) cin>>seq[i];
	for (int i = 1; i <= n; i++) bit[i] = __builtin_popcount(seq[i]);
	int s = 2*n+2;
	int t = s+1;
	for (int i = 0; i <= t; i++) last[i] = -1;
	add_edge(s, 0, m, 0);
	for (int i = 1; i <= n; i++)
		add_edge(0, i+n, 1, bit[i]), add_edge(s, i, 1, 0), add_edge(i+n, t, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) add_edge(i, n+j, 1, (seq[i]==seq[j])?0:bit[j]);
	int ans = minCostMaxFlow(t+1, s, t).second;
	int op = 0;
	int vars = 0;
	for (int i = 1; i <= n; i++) if (!cap2[0][i+n]) {
		change[i] = true;
		var[i] = vars;
		int curr = i;
		for (int j = curr+1; j <= n; j++) if (!cap2[curr][j+n]) {
			change[j] = (seq[curr] != seq[j]);
			var[j] = vars;
			curr = j;
		}
		vars++;
	}
	for (int i = 1; i <= n; i++) op += change[i];
	cout<<op+n<<" "<<ans<<endl;
	for (int i = 1; i <= n; i++) {
		if (change[i]) cout<<char('a'+var[i])<<"="<<seq[i]<<endl;
		cout<<"print("<<char('a'+var[i])<<")"<<endl;
	}
	return 0;
}


