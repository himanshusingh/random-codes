/* Problem Link: http://www.codeforces.com/problemset/problem/237/E */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int oo = 1e9;
int cap[128][128], cost[128][128];
int cnt[26];

int minCostMaxFlow(int nodes, int s, int t)
{
	int ret = 0;
	while (true) {
		vector<int> dist(nodes, oo);
		vector<int> par(nodes, -1);
		dist[s] = 0;
		while (true) {
			bool updated = false;
			for (int i = 0; i < nodes; i++) if (dist[i] < oo)
				for (int j = 0; j < nodes; j++) if (cap[i][j] > 0 && dist[j] > dist[i] + cost[i][j]) {
					updated = true;
					dist[j] = dist[i] + cost[i][j];
					par[j] = i;
				}
			if (!updated) break;
		}
        if (dist[t] >= oo) break;

        ret += dist[t];
        int curr = t;
        while (par[curr] != -1) {
            int prev = par[curr];
            cap[curr][prev]++;
            cap[prev][curr]--;
            curr = prev;
        }
	}
    for (int c = 0; c < 26; c++) if (cap[nodes-2-26+c][t]) return -1;
    return ret;
}
int main()
{
	string need;
	cin>>need;
	int n;
	cin>>n;
	for (int i = 0; i < need.size(); i++) cnt[need[i]-'a']++;
	int nodes = n+26+2;
	int s = nodes-2, t = nodes-1;
	for (int i = 0; i < 26; i++) cap[n+i][t] = cnt[i];

	for (int i = 0; i < n; i++) {
		string str;
		int lt;
		cin>>str>>lt;
		cap[s][i] = lt;
		cost[s][i] = i+1;
		for (int c = 0; c < 26; c++) cnt[c] = 0;
		for (int j = 0; j < str.size(); j++) cnt[str[j]-'a']++;
		for (int c = 0; c < 26; c++) cap[i][n+c] = cnt[c];
	}
	cout<<minCostMaxFlow(nodes, s, t)<<endl;
	return 0;
}