#include <iostream>
#include <cstdio>
using namespace std;
const int mod = int(1e9)+7;
typedef long long ll;

ll dp[333][100101];
int a[333];
int to[333], in[333];
int coin[333], coins;
bool vis[333];
int main()
{
	int n, q, t;
	cin>>n>>q>>t;
	for (int i = 1; i <= n; i++) cin>>a[i];
	for (int i = 1; i <= n; i++) to[i] = -1;
	for (int i = 1; i <= q; i++) {
		int b, c;
		cin>>b>>c;
		to[b] = c;
		in[c]++;
	}
	ll must = 0;
	for (int i = 1; i <= n; i++) if (!in[i]) {
		int sum = 0;
		int x = i;
		while (1) {
			vis[x] = true;
			sum += a[x];
			coin[coins++] = sum;
			if (to[x] != -1) must += sum;
			if (to[x] == -1) break;
			x = to[x];
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		cout<<0<<endl;
		return 0;
	}
	if (must > t) {
		cout<<0<<endl;
		return 0;
	}
	t -= must;
	dp[0][0] = 1;
	for (int c = 0; c < coins; c++)
		for (int s = 0; s <= t; s++) {
			dp[c+1][s] = dp[c][s];
			if (s >= coin[c])
				dp[c+1][s] = (dp[c+1][s] + dp[c+1][s-coin[c]])%mod;
		}
	cout<<dp[coins][t]<<endl;
	return 0;
}