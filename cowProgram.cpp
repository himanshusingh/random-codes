#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 2e5+7;
int vis[MAX_N][2];
long long G[MAX_N];
vector< pair<long long,int> > curr;
long long ans[MAX_N][2];
bool invalid[MAX_N][2];
long long py[MAX_N][2];
int N;
long long y;
int tm = 1;
void dfs(long long x, int s)
{
	vis[x][s] = tm;
	py[x][s] = y;
	curr.push_back(make_pair(x, s));
	long long nx;
	if (s) {
		nx = x - G[x];
		y += G[x];
	} else {
		nx = x + G[x];
		y += G[x];
	}
	s = !s;
	if (nx <= 0 || nx > N) {
		for (int i = 0; i < curr.size(); i++) {
			ans[curr[i].first][curr[i].second] = y - py[curr[i].first][curr[i].second];
		}
		return;
	}

	if (vis[nx][s]) {
		if (vis[nx][s] != tm) {
			for (int i = 0; i < curr.size(); i++) {
				ans[curr[i].first][curr[i].second] = ans[nx][s] + y - py[curr[i].first][curr[i].second];;
				invalid[curr[i].first][curr[i].second] = invalid[nx][s];
			}
			return;
		}
		for (int i = 0; i < curr.size(); i++) {
			ans[curr[i].first][curr[i].second] = -1;
			invalid[curr[i].first][curr[i].second] = true;
		}
		return;
	}
	dfs(nx, s);
}
int main()
{
	//freopen("in.in", "r", stdin);
	cin>>N;
	for (int i = 2; i <= N; i++) cin>>G[i];
	vis[1][0] = true;
	invalid[1][0] = true;
	for (int i = 2; i <= N; i++)
		for (int s = 1; s <= 1; s++) if (!vis[i][s]) {
			y = 0;
			curr.clear();
			dfs(i, s);
			tm++;
		}
	for (int i = 2; i <= N; i++) {
		if (invalid[i][1]) cout<<"-1"<<endl;
		else cout<<ans[i][1] + i-1<<endl;
	}
	return 0;
}