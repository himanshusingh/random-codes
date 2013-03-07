#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int oo = 1e9;
const int MAX_E = 10000;
const int MAX_N = 5000;
int cap[MAX_E], flow[MAX_E];
int edges, to[MAX_E];
int cost[MAX_E];
int last[MAX_N], next[MAX_N];
void add_edge(int u, int v, int capacity, int cst)
{
    cap[edges] = capacity, flow[edges] = 0, to[edges] = v;
    cost[edges] = cst;
    next[u] = last[u], last[u] = edges++;

    cap[edges] = 0, flow[edges] = 0, to[edges] = u;
    cost[edges] = -cst;
    next[v] = last[v], last[v] = edges++;
}
void minCostCirculation(int nodes)
{
    while (true) {
        vector<int> dist(nodes+1, oo/2);
        vector<int> pre(nodes+1, -1);
        vector<int> ped(nodes+1, -1);
        for (int i = 0; i < nodes; i++)
            for (int e = 0; e < edges; e++) if (cap[e] > 0) {
                int u = to[e^1], v = to[e];
                if (dist[v] > dist[u] + cost[e]) {
                    pre[v] = u;
                    ped[v] = e;
                    dist[v] = dist[u] + cost[e];
                }
            }
        int start = -1;
        for (int e = 0; e < edges; e++) if (cap[e] > 0) {
            int u = to[e^1], v = to[e];
            if (dist[v] > dist[u] + cost[e]) {
                start = v;
                break;
            }
        }
        if (start == -1) break;
        vector<bool> vis(nodes+1, false);
        vector<int> path;
        int curr = start;
        do {
            vis[curr] = true;
            path.push_back(curr);
            curr = pre[curr];
        } while (!vis[curr]);
        for (int i = 0; i < path.size(); i++) if (path[i] == curr) {
            start = i;
            break;
        }
        int minf = oo;
        for (int i = start; i < path.size(); i++) minf = min(minf, cap[ped[path[i]]]);
        for (int i = start; i < path.size(); i++) {
            int e = ped[path[i]];
            cap[e] -= minf, cap[e^1] += minf;
        }
    }
}
int beg[MAX_N], end[MAX_N], cst[MAX_N];
int main()
{
    int n, k;
    cin>>n>>k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin>>beg[i]>>end[i]>>cst[i];
        end[i] += beg[i];
        mp[beg[i]] = 1;
        mp[end[i]] = 1;
    }
    int idx = 0;
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
        it->second = idx;
        idx++;
    }
    for (int i = 0; i < n; i++)
        add_edge(mp[end[i]], mp[beg[i]], 1, -cst[i]);
    for (int i = 0; i < idx-1; i++)
        add_edge(i, i+1, k, 0);
    minCostCirculation(idx);
    for (int i = 0; i < 2*n; i += 2)
        if (!cap[i]) cout<<1<<" ";
        else cout<<0<<" ";
    cout<<endl;
    return 0;
}