#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 1e5+7;
vector<int>G[MAX_N];
string treestring(int idx, int par){
  vector<string> vs;
  for(int i=0;i<G[idx].size();i++) if (G[idx][i] != par)
    vs.push_back(treestring(G[idx][i], idx));
  sort(vs.begin(),vs.end());
  string s="(";
  for(int i=0;i<vs.size();i++)
    s+=vs[i]+",";
  s+=")";
  return s;
}
int main()
{
//	freopen("in.in", "r", stdin);
	int test;
	scanf ("%d", &test);
	while (test--) {
		int n, root;
		scanf ("%d", &n);
		scanf ("%d", &root);
		for (int i = 0; i <= n; i++) G[i].clear();
		for (int i = 0; i < n-1; i++) {
			int a, b;
			scanf ("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		string t1 = treestring(root, -1);
		scanf ("%d", &root);
		for (int i = 0; i <= n; i++) G[i].clear();
		for (int i = 0; i < n-1; i++) {
			int a, b;
			scanf ("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		cout<<(treestring(root, -1) == t1)<<endl;
	}
	return 0;
}