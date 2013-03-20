#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int mod = 100001;
const int MAX_N = 1e8+8;
int ans[111];
pair<int,int> qu[111];
int main()
{
	int test;
	scanf ("%d", &test);
	int maxn = 0;
	for (int t = 0; t < test; t++) {
		int n;
		scanf ("%d", &n);
		maxn = max(n, maxn);
		qu[t] = make_pair(n, t);
	}
	sort(qu, qu+test);
	int dp[5] = {1, 2, 3, 4, 5};
	int idx = 0;
	for (int i = 0; i < 5; i++)
		while (idx < test && qu[idx].first == i+1) ans[qu[idx].second] = dp[i], idx++;
	for (int i = 6; i <= maxn && idx < test; i++) {
		int x = (1 + dp[2]+dp[3]-dp[0] + mod)%mod;
	    for (int j = 0; j < 4; j++) dp[j] = dp[j+1];
	    dp[4] = x;
     	while (idx < test && qu[idx].first == i) ans[qu[idx].second] = x, idx++;
	}
	for (int t = 0; t < test; t++)
		printf ("%d\n", (ans[t]+mod)%mod);
	return 0;
}