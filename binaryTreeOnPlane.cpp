#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 1024;
int N;
int x[MAX_N], y[MAX_N];
const double oo = 1e9;
const int MAX_E = 1000000;
int cap[MAX_E], flow[MAX_E];
int edges, to[MAX_E];
double cost[MAX_E];
int last[MAX_N], next[MAX_E];
void add_edge(int u, int v, int capacity, double cst)
{
    cap[edges] = capacity, flow[edges] = 0, to[edges] = v;
    cost[edges] = cst;
    next[edges] = last[u], last[u] = edges++;

    cap[edges] = 0, flow[edges] = 0, to[edges] = u;
    cost[edges] = -cst;
    next[edges] = last[v], last[v] = edges++;
}
int ped[MAX_N], pre[MAX_N];
double spfa(int nodes, int s, int t)
{
    vector<double> dist(nodes+1, oo);
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

pair<int, double> minCostMaxFlow(int nodes, int s, int t)
{
    int flow = 0;
    double d, ret = 0;
    while ((d = spfa(nodes, s, t)) + 7 < oo) {
        int minf = oo;
        for (int i = t; i != s; i = pre[i]) minf = min(minf, cap[ped[i]]);
            for (int i = t; i != s; i = pre[i]) {
                cap[ped[i]] -= minf;
                cap[ped[i]^1] += minf;
            }
            flow += minf;
            ret += d*minf;
    }
    return make_pair(flow, ret);
}
double dist(int a, int b)
{
    return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b]) + 1.0*(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{

   cin>>N;
   for (int i = 0; i < N; i++)
    cin>>x[i]>>y[i];
    int nodes = 2*N+2;
    int s = 2*N, t = 2*N+1;
    for (int i = 0; i <= nodes; i++) last[i] = -1;
    for (int i = 0; i < N; i++) {
        add_edge(s, i, 2, 0);
        add_edge(i+N, t, 1, 0);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) if (y[i] > y[j])
            add_edge(i, j+N, 1, dist(i, j));
    pair<int, double> res = minCostMaxFlow(nodes, s, t);
    if (res.first != N-1) cout<<"-1"<<endl;
    else printf ("%0.12lf\n", res.second);
    return 0;
}