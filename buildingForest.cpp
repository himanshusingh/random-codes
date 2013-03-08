/* Problem Link: http://www.codeforces.com/problemset/problem/195/E */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 1e5+7;
const int mod = 1e9+7;
int parent[MAX_N];
long long depth[MAX_N];
pair<int, long long> getp(int x)
{
	if (parent[x] == x) return make_pair(parent[x], depth[x]);
	pair<int, long long> ret = getp(parent[x]);
	parent[x] = ret.first;
	depth[x] = (depth[x] + ret.second)%mod;
	return make_pair(parent[x], depth[x]);
}
void add(int root, int n, long long x)
{
	parent[root] = n;
	depth[root] = x%mod;
}
int main()
{
	int n;
	cin>>n;
	long long ans = 0;
	for (int i = 1; i<= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int k, v;
		long long x;
		cin>>k;
		for (int j = 1; j <= k; j++) {
			cin>>v>>x;
			int root = getp(v).first;
			ans = (ans + depth[v] + x)%mod;
			add(root, i, x + depth[v]);
		}
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}