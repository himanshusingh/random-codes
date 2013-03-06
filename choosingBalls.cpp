/* Problem Link: http://www.codeforces.com/contest/264/problem/C */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = int(1e5)+7;

long long dp[MAX_N];
bool valid[MAX_N];
long long val[MAX_N];
int color[MAX_N];

int main()
{
	int n, queries;
	cin>>n>>queries;

	for (int i = 1; i <= n; i++) cin>>val[i];
	for (int i = 1; i <= n; i++) cin>>color[i];

	for (int q = 1; q <= queries; q++) {
        long long a, b;
        cin>>a>>b;
        int best = 0, secondBest = 0;
        memset(dp, 0, sizeof(dp));
        memset(valid, false, sizeof(valid));

        for (int i = 1; i <= n; i++) {
            int c = color[i];
            if (valid[c])
                dp[c] = max(dp[c], dp[c] + a*val[i]);
            else
                dp[c] = b*val[i];
            if (best == c)
                dp[c] = max(dp[c], dp[secondBest] + b*val[i]);
            else
                dp[c] = max(dp[c], dp[best] + b*val[i]);
    
            if (dp[c] >= dp[best]) {
                int tmp = best;
                best = c;
                if (tmp != c) secondBest = tmp;
            } else if (dp[c] >= dp[secondBest]) {
                secondBest = c;
            }
            valid[c] = true;
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        cout<<ans<<endl;
    }
	return 0;
}
