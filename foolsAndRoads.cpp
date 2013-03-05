#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int MAX_N = int(1e5)+7;

vector< vector<int> > Graph;
vector< vector<int> > eid;
int nodes;
/* LCA */
class LCA
{
    vector< vector<int> > parent;      // [n][i] -- (2^i)th parent of n
    int logn;
    vector<int> tin, tout;
    int time;
public:
    LCA(vector< vector<int> >& Graph, int nodes)
    {
        for (logn = 0; (1<<logn) < nodes; ++logn)
            ;
        parent.resize(nodes+1);
        tin.resize(nodes+1);
        tout.resize(nodes+1);
        for (int idx = 0; idx <= nodes; idx++) parent[idx].resize(logn);
        time = 0;
        dfs(1, 0, Graph);
    }

    void dfs(int node, int par, vector< vector<int> >& Graph)
    {
        tin[node] = ++time;
        parent[node][0] = par;
        for (int i = 1; i < logn; i++)
            parent[node][i] = parent[parent[node][i-1]][i-1];

        for (int child = 0; child < Graph[node].size(); child++) if (Graph[node][child] != par)
            dfs(Graph[node][child], node, Graph);
        tout[node] = ++time;
    }

    // checks if a is ancestor of b
    bool isAncestor(int a, int b)
    {
        return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
    }
    // returns the lca of a and b
    int get(int a, int b)
    {
        if (isAncestor(a, b)) return a;
        if (isAncestor(b, a)) return b;
        for (int i = logn-1; i >= 0; i--)
            if (parent[a][i] && !isAncestor(parent[a][i], b))
                a = parent[a][i];
        return parent[a][0];
    }
};


int counter[MAX_N];
int ans[MAX_N];
int dfs(int x, int p)
{
  int cnt = 0;
  for (int i = 0; i < Graph[x].size(); i++) if (Graph[x][i] != p) {
    int c = dfs(Graph[x][i], x);
    ans[eid[x][i]] = c;
    cnt += c;
  }
  cnt += counter[x];
  return cnt;
}

int main()
{

  cin>>nodes;
  Graph.resize(nodes+1);
  eid.resize(nodes+1);

  for (int idx = 1; idx <= nodes-1; idx++) {
    int from, to;
    cin>>from>>to;
    Graph[from].push_back(to);
    Graph[to].push_back(from);
    eid[from].push_back(idx);
    eid[to].push_back(idx);
  }
  LCA lca(Graph, nodes);
  int fools;
  cin>>fools;
	for (int fool = 1; fool <= fools; fool++) {
    int from, to;
    cin>>from>>to;
    int l = lca.get(from, to);
    counter[from] += 1;
    counter[to] += 1;
    counter[l] -= 2;
	}
  dfs(1, 0);
  for (int idx = 1; idx <= nodes-1; idx++)
    cout<<ans[idx]<<endl;
  return 0;
}