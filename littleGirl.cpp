#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 1e5+7;
vector< vector<int> > trees;
vector<int> centerTree;

void bitUpdate(vector<int>& tree, int idx, int v)
{
  if (!idx) return;
  for (int x = idx; x < tree.size(); x += (x&-x))
    tree[x] += v;
}
int bitRead(vector<int>& tree, int idx)
{
  int ret = 0;
  for (int x = idx; x; x -= (x&-x))
    ret += tree[x];
  return ret;
}
int quota[MAX_N];

int treeId[MAX_N];
int dist[MAX_N];

int nodes, queries;
vector<int> G[MAX_N];
int dfs(int x, int p, int tid, int d)
{
  treeId[x] = tid;
  dist[x] = d;
  if (G[x].size() == 1) return d;
  for (int i = 0; i < G[x].size(); i++) if (G[x][i] != p)
    return dfs(G[x][i], x, tid, d+1);
}
int main()
{
  cin>>nodes>>queries;
  for (int i = 1; i <= nodes-1; i++) {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  centerTree.resize(nodes+2);
  int tid = 0;
  for (int i = 0; i < G[1].size(); i++) {
    int x = G[1][i];
    int n = dfs(x, 1, tid, 1);
    vector<int> tree(n+2, 0);
    trees.push_back(tree);
    tid++;
  }
  treeId[1] = tid+1;
  for (int q = 1; q <= queries; q++) {
    int type;
    cin>>type;
    if (type == 0) {
      int v, x ,d;
      cin>>v>>x>>d;
      tid = treeId[v];
      if (dist[v] <= d) {
        centerTree[0] += x;
        bitUpdate(centerTree, d-dist[v], x);
        if (d-dist[v] && v != 1) {
          bitUpdate(trees[tid], 1, -x);
          bitUpdate(trees[tid], d-dist[v]+1, x);
        }
      }
      if (v == 1) continue;
      int up = min(dist[v]+d, int(trees[tid].size())-2);
      int lo = max(dist[v]-d, 1);
      bitUpdate(trees[tid], up+1, -x);
      bitUpdate(trees[tid], lo, x);
    } else {
      int v;
      cin>>v;
      tid = treeId[v];
      if (v == 1) cout<<centerTree[0]<<endl;
      else {
	     int res = bitRead(trees[tid], dist[v]) + bitRead(centerTree, nodes) - bitRead(centerTree, dist[v]-1);
	     cout<<res<<endl;
      }
    }
  }
  return 0;
}
